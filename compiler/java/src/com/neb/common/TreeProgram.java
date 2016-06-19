package com.neb.common;

import com.neb.Main;
import com.neb.common.codes.*;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * Created by benlindsey on 09/02/2016.
 */
public abstract class TreeProgram {
    protected List<StringVariable> constants = new ArrayList<>();
    protected List<StringVariable> stateVariables = new ArrayList<>();
    //protected LinkedHashMap<StringVariable, String> commonExpressions = new LinkedHashMap<>();
    protected Map<String, ICode> updateFunctions = new HashMap<>();
    protected List<StringRandomSource> headerRandomSources = new ArrayList<>();
    protected String output;
    protected ICode payoff;
    protected List<String> commonSubExpressions;

    public TreeProgram addConstant(StringVariable constant) {
        constants.add(constant);

        return this;
    }

    public TreeProgram addUpdateFunction(String name, ICode update) {
        updateFunctions.put(name, update);

        return this;
    }

    public TreeProgram addStateVariable(StringVariable variable) {
        stateVariables.add(variable);

        return this;
    }

    public TreeProgram setOutputValue(String name) {
        output = name;

        return this;
    }

    public TreeProgram setPayoff(ICode payoff) {
        this.payoff = payoff;

        return this;
    }

    protected StringVariable getOutputValue() {
        return stateVariables.stream()
                .filter(variable -> variable.name.equals(output))
                .findFirst()
                .get();
    }

    protected int getSimulations() {
        return Integer.parseInt(constants.stream()
                .filter(variable -> variable.name.equals("Simulations"))
                .findFirst()
                .get().initialValue);
    }

    protected int getSteps() {
        return Integer.parseInt(constants.stream()
                .filter(variable -> variable.name.equals("Steps"))
                .findFirst()
                .get().initialValue);
    }

    protected float getEPS() {
        return Float.parseFloat(constants.stream()
                .filter(variable -> variable.name.equals("EPS"))
                .findFirst()
                .get().initialValue);
    }

    protected String setToNumberGenerator(RandomSet set) {
        switch (set) {
            case Z:
                return "uniform_int_distribution";
            case R:
                return "uniform_real_distribution";
            case N:
                return "normal_distribution";
            default:
                throw new RuntimeException("Invalid random set, unsure which number generator to use");
        }
    }

    public TreeProgram addRandomSource(StringRandomSource randomSource) {
        headerRandomSources.add(randomSource);

        return this;
    }


    public TreeProgram merge(TreeProgram nextResult) {
        constants.addAll(nextResult.constants);
        stateVariables.addAll(nextResult.stateVariables);
        updateFunctions.putAll(nextResult.updateFunctions);
        headerRandomSources.addAll(nextResult.headerRandomSources);
        output = output == null ? nextResult.output : output;
        payoff = payoff == null ? nextResult.payoff : payoff;

        return this;
    }

    protected List<String> getHeaderConstants() {
        return getHeaderConstants(this::typeToHeaderType, true);
    }

    protected List<String> getHeaderConstants(boolean addOutput) {
        return getHeaderConstants(this::typeToHeaderType, addOutput);
    }

    protected List<String> getHeaderConstants(Function<Type, String> convertType, boolean addOutput) {
        List<String> result = constants.stream()
                .map(constant -> constantToString(constant, convertType.apply(constant.type)))
                .collect(Collectors.toList());

        if(addOutput) {
            StringVariable outputVariable = getOutputValue();
            outputVariable = new StringVariable(outputVariable.type, "OUTPUT_INITIAL", outputVariable.initialValue);
            result.add(constantToString(outputVariable, convertType.apply(outputVariable.type)));
        }

        return result;
    }

    protected StringVariable getConstantByName(String name) {
        return constants.stream().filter(variable -> variable.name.equals(name)).findFirst().get();
    }

    protected List<String> getRandomSource(boolean fast) {
        List<String> code = new ArrayList<>();

        List<String> args = headerRandomSources.stream()
                .map(source -> String.format("%s* %s",
                        typeToHeaderType(Type.fromRandomSet(source.set)), source.name))
                .collect(Collectors.toList());

        code.add(String.format("\ninline void generateInput(%s) {", String.join(", ", args)));
        code.add(String.format("  auto array_size = Simulations * Steps;"));
        code.add("");
        code.add("  std::random_device rd;");
        code.add("  std::mt19937 gen(rd());");

        headerRandomSources.stream().forEach(source ->
                code.add(String.format("  std::%s<> %s(%s, %s);",
                        setToNumberGenerator(source.set), source.name + "Gen", source.from, source.to)));

        code.add("");
        code.add(String.format("  for (%s i = 0; i < array_size; ++i) {", typeToHeaderType(Type.INT)));

        headerRandomSources.stream().forEach(source ->
                code.add(String.format("    %s[i] = %s;",
                        source.name, fast? "4" : source.name + "Gen(gen)")));

        code.add("  }");
        code.add("}");

        return code;
    }

    protected String constantToString(StringVariable constant, String type) {
        return Type.isArray(constant.type) ?
                String.format("%s %s[%s] = %s;", type, constant.name, constant.elements, constant.initialValue) :
                String.format("%s %s = %s;", type, constant.name, constant.initialValue);
    }

    protected List<String> getCommonSubExpressions() {
        List<String> result = new ArrayList<>();

        if(!Main.OPTIMISE_SUB_EXPRESSIONS) {
            return result;
        }

        if(commonSubExpressions != null) {
            return commonSubExpressions;
        }

        LinkedHashMap<StringVariable, String> commonExpressions = new LinkedHashMap<>();
        Map<MathUnaryFunctionCode, String> unaryFunctions = new LinkedHashMap<>();
        Map<MathBinaryFunctionCode, String> binaryFunctions = new LinkedHashMap<>();

        AtomicInteger uuids = new AtomicInteger();

        updateFunctions.entrySet().stream()
                .forEach(entry -> {
                    // EXTRACT ARRAY REFERENCES
                    entry.getValue().forEachWhere(
                                code -> {
                                    String name = code.toString().split("Now")[0];
                                    StringVariable array = getConstantByName(name);
                                    commonExpressions.put(new StringVariable(array.type, code.toString()), name + "[i % 3]"); //todo
                                },
                                ICode::isArrayReference
                        );

                    // EXTRACT BINARY CALLS
                    entry.getValue().forEachWhere(
                            code -> {
                                MathBinaryFunctionCode function = (MathBinaryFunctionCode) code;

                                if(!binaryFunctions.containsKey(function)) {
                                    int number = uuids.getAndIncrement();
                                    String name = "bFunc" + number;

                                    commonExpressions.put(new StringVariable(Type.REAL, name), function.toString());
                                    binaryFunctions.put(function, name);
                                }

                                function.replace(new TreeCode(binaryFunctions.get(function)));
                            },
                            ICode::isBinaryFunction
                    );

                    uuids.set(0);

                    // EXTRACT UNARY CALLS
                    entry.getValue().forEachWhere(
                            code -> {
                                MathUnaryFunctionCode function = (MathUnaryFunctionCode) code;

                                if(!unaryFunctions.containsKey(function)) {
                                    int number = uuids.getAndIncrement();
                                    String name = "uFunc" + number;

                                    commonExpressions.put(new StringVariable(Type.REAL, name), function.toString());
                                    unaryFunctions.put(function, name);
                                }

                                function.replace(new TreeCode(unaryFunctions.get(function)));
                            },
                            ICode::isUnaryFunction
                    );
                });

        if(commonExpressions.size() > 0) {
            commonExpressions.entrySet().stream().forEach(variable ->
                    result.add(String.format("%s %s = %s;",
                            typeToHeaderType(variable.getKey().type), variable.getKey().name, variable.getValue())));

            result.add("");
        }

        commonSubExpressions = result;

        return result;
    }

    protected abstract String typeToHeaderType(Type type);
}
