package com.neb.ad;

import com.neb.common.StringRandomSource;
import com.neb.common.StringVariable;
import com.neb.common.TreeProgram;
import com.neb.common.Type;
import com.neb.common.codes.TreeCode;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by Ben on 23/01/2016.
 */
public class ADProgram extends TreeProgram {
    private String sensitivityFunction;
    private String sensitivityVariable;

    public ADProgram addUpdateFunction(String name, TreeCode update) {
        super.addUpdateFunction(name, update);

        return this;
    }

    public ADProgram addStateVariable(StringVariable variable) {
        super.addStateVariable(variable);

        return this;
    }

    public ADProgram addRandomSource(StringRandomSource randomSource) {
        super.addRandomSource(randomSource);

        return this;
    }

    public ADProgram addConstant(StringVariable constant) {
        super.addConstant(constant);

        return this;
    }

    public ADProgram addSensitivity(String function, String variable) {
        sensitivityFunction = function;
        sensitivityVariable = variable;

        return this;
    }

    public ADProgram merge(ADProgram nextResult) {
        super.merge(nextResult);

        sensitivityFunction = sensitivityFunction == null ? nextResult.sensitivityFunction : sensitivityFunction;
        sensitivityVariable = sensitivityVariable == null ? nextResult.sensitivityVariable : sensitivityVariable;

        return this;
    }

    public ADProgram setOutputValue(String name) {
        super.setOutputValue(name);

        return this;
    }

    public ADProgram setPayoff(TreeCode payoff) {
        super.setPayoff(payoff);

        return this;
    }

    @Override
    protected String typeToHeaderType(Type type) {
        switch (type) {
            case INT:
            case INT_ARRAY:
                return "int";
            case REAL:
            case REAL_ARRAY:
                return "float";
            default:
                throw new RuntimeException("Unknown type, cannot convert to opencl type");
        }
    }

    private List<String> getRunArgs() {
        List<String> args = headerRandomSources.stream()
                .map(source -> String.format("%s %s",
                        typeToHeaderType(Type.fromRandomSet(source.set)), source.name))
                .collect(Collectors.toList());

        return args;
    }

    public List<String> getRunOnce() {
        List<String> code = new ArrayList<>();

        List<String> args = getRunArgs();

        StringVariable function = stateVariables.stream().filter(stringVariable ->
                stringVariable.name.equals(sensitivityFunction)).findFirst().get();

        String functionType = typeToHeaderType(function.type);

        code.add(String.format("\n%s stateUpdate(%s) {", functionType,  String.join(", ", args)));

        stateVariables.stream().forEach(variable ->
                code.add(String.format("  %s %s = %s;",
                        typeToHeaderType(variable.type), variable.name, variable.initialValue)));

        code.add("");
        code.add("  for(int i = 0; i < Steps; i++) {");
        code.add("    const int id = currentHeight * Steps + i;");
        code.add("");

        getCommonSubExpressions().stream().forEach(line -> code.add(String.format("    %s", line)));

        code.add(String.format("  %s result = %s;",
                typeToHeaderType(function.type), updateFunctions.get(function.name)));

        code.add("}");

        return code;
    }

    public List<String> getMacros() {
        List<String> macros = new ArrayList<>();

        for(int i = 0; i < headerRandomSources.size(); i++) {
            StringRandomSource source = headerRandomSources.get(i);

            macros.add(String.format("%s%s %s = 1;%s", //todo what value
                    i == 0 ? "#define INPUTS_SETUP " : "", typeToHeaderType(Type.fromRandomSet(source.set)),
                    source.name, (i == headerRandomSources.size() - 1 ? "" : "\\")));
        }

        List<String> names = headerRandomSources.stream()
                .map(source -> String.format("%s", source.name))
                .collect(Collectors.toList());

        macros.add(String.format("\n#define RUN_ARGS %s", String.join(", ", names)));

        return macros;
    }

    public List<String> getHeader() {
        List<String> completeHeader = new ArrayList<>();

        completeHeader.add("// AD HEADER for " + sensitivityFunction + " by " + sensitivityVariable);

        completeHeader.add("#include <stdlib.h>");
        completeHeader.add("#include <random>");
        completeHeader.add("#include <algorithm>");
        completeHeader.add("#include <cmath>\n");
        completeHeader.add("using namespace std;\n");


        completeHeader.addAll(getHeaderConstants());
        completeHeader.addAll(getRunOnce());
        completeHeader.addAll(getMacros());

        return completeHeader;
    }

    @Override
    public String toString() {
        JSONObject json = new JSONObject();

        json.put("header", getHeader());

        return json.toString();
    }
}
