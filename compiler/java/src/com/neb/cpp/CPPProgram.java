package com.neb.cpp;

import com.neb.common.*;
import com.neb.common.codes.TreeCode;
import org.json.JSONObject;

import java.util.*;
import java.util.stream.Collectors;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPProgram extends TreeProgram {

    public CPPProgram addUpdateFunction(String name, TreeCode update) {
        super.addUpdateFunction(name, update);

        return this;
    }

    public CPPProgram addStateVariable(StringVariable variable) {
        super.addStateVariable(variable);

        return this;
    }

    public CPPProgram addRandomSource(StringRandomSource randomSource) {
        super.addRandomSource(randomSource);

        return this;
    }

    public CPPProgram addConstant(StringVariable constant) {
        super.addConstant(constant);

        return this;
    }

    public CPPProgram merge(CPPProgram nextResult) {
        super.merge(nextResult);

        return this;
    }

    public CPPProgram setOutputValue(String name) {
        super.setOutputValue(name);

        return this;
    }

    public CPPProgram setPayoff(TreeCode payoff) {
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
                .map(source -> String.format("%s* %s",
                        typeToHeaderType(Type.fromRandomSet(source.set)), source.name))
                .collect(Collectors.toList());

        args.add("float* output");

        return args;
    }

    public List<String> getRunOnce() {
        List<String> code = new ArrayList<>();

        List<String> args = getRunArgs();

        code.add(String.format("\ninline void runOnce(int currentHeight, %s) {",  String.join(", ", args)));

        stateVariables.stream().forEach(variable ->
                code.add(String.format("  %s %s = %s;",
                        typeToHeaderType(variable.type), variable.name, variable.initialValue)));

        code.add("");
        code.add("  for(int i = 0; i < Steps; i++) {");
        code.add("    const int id = currentHeight * Steps + i;");
        code.add("");

        getCommonSubExpressions().stream().forEach(line -> code.add(String.format("    %s", line)));

        stateVariables.stream().forEach(variable ->
                code.add(String.format("    %s %sTemp = %s;",
                        typeToHeaderType(variable.type), variable.name, updateFunctions.get(variable.name))));

        code.add("");

        stateVariables.stream().forEach(variable ->
                code.add(String.format("    %1$s = %1$sTemp;", variable.name)));

        code.add(String.format("\n    output[id] = %s;", output));

        code.add("  }");
        code.add("}");

        return code;
    }

    public List<String> getMacros() {
        List<String> macros = new ArrayList<>();

        macros.add("");

        for(int i = 0; i < headerRandomSources.size(); i++) {
            StringRandomSource source = headerRandomSources.get(i);

            macros.add(String.format("%sint %sSize = sizeof(%s) * arrayWidth * arrayHeight;\\",
                    i == 0 ? "#define INPUTS_SETUP " : "", source.name, typeToHeaderType(Type.fromRandomSet(source.set))));

            macros.add(String.format("%1$s* %2$s = (%1$s*)malloc(%2$sSize);\\",
                    typeToHeaderType(Type.fromRandomSet(source.set)), source.name));
        }

        macros.add("int dstSize = sizeof(float) * arrayWidth * arrayHeight;\\");
        macros.add("float* dst = (float*)malloc(dstSize);\\");

        List<String> nullChecks = headerRandomSources.stream()
                .map(source -> String.format("NULL == %s", source.name))
                .collect(Collectors.toList());

        nullChecks.add("NULL == dst");

        macros.add(String.format("if (%s)\\", String.join(" || ", nullChecks)));
        macros.add("{\\");
        macros.add("\tLogError(\"Error: _aligned_malloc failed to allocate buffers.\\n\");\\");
        macros.add("\treturn -1;\\");
        macros.add("}\\\n\\");
        macros.add(String.format("generateInput(%s);", String.join(", ", headerRandomSources.stream()
                .map(source -> source.name).collect(Collectors.toList()))));

        macros.add("");

        List<String> names = headerRandomSources.stream()
                .map(source -> String.format("%s", source.name))
                .collect(Collectors.toList());

        names.add("dst");

        macros.add("");

        macros.add(String.format("#define INPUTS_FREE %s", String.join(" ", names.stream()
                .map(name -> String.format("free(%s);", name))
                .collect(Collectors.toList()))));

        macros.add(String.format("#define RUN_ARGS %s", String.join(", ", names)));

        return macros;
    }

    public List<String> getHeader(boolean timeOnly, boolean fast) {
        List<String> completeHeader = new ArrayList<>();

        completeHeader.add("#include <stdlib.h>");
        completeHeader.add("#include <random>");
        completeHeader.add("#include <algorithm>");
        completeHeader.add("#include <cmath>\n");
        completeHeader.add("using namespace std;\n");

        if(timeOnly) {
            completeHeader.add("#define TIMEONLY");
        }

        completeHeader.addAll(getHeaderConstants());
        completeHeader.addAll(getRandomSource(fast));
        completeHeader.addAll(getRunOnce());
        completeHeader.addAll(getMacros());

        return completeHeader;
    }

    @Override
    public String toString() {
        JSONObject json = new JSONObject();

        json.put("header", getHeader(false, false));

        return json.toString();
    }
}
