package com.neb.cppML;

import com.neb.common.*;
import com.neb.common.codes.StateVariableCode;
import com.neb.common.codes.TreeCode;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPMLProgram extends TreeProgram {

    public CPPMLProgram addUpdateFunction(String name, TreeCode update) {
        super.addUpdateFunction(name, update);

        return this;
    }

    public CPPMLProgram addStateVariable(StringVariable variable) {
        super.addStateVariable(variable);

        return this;
    }

    public CPPMLProgram addRandomSource(StringRandomSource randomSource) {
        super.addRandomSource(randomSource);

        return this;
    }

    public CPPMLProgram addConstant(StringVariable constant) {
        super.addConstant(constant);

        return this;
    }

    public CPPMLProgram merge(CPPMLProgram nextResult) {
        super.merge(nextResult);

        return this;
    }

    public CPPMLProgram setOutputValue(String name) {
        super.setOutputValue(name);

        return this;
    }

    public CPPMLProgram setPayoff(StateVariableCode payoff) {
        super.setPayoff(payoff);

        return this;
    }

    public List<String> getMultilevel() {
        List<String> code = new ArrayList<>();

        code.add("struct _multilevel {");
        code.add("    constexpr static int N0    = 200;     // initial samples on each level");
        code.add("    constexpr static int Lmin  = 2;       // minimum refinement level");
        code.add("    constexpr static int Lmax  = 10;      // maximum refinement level");
        code.add("};");

        return code;
    }

    public List<String> getRegression() {
        List<String> code = new ArrayList<>();

        code.add("struct _regression {");
        code.add("    constexpr static int M = 2;           // Refinement Factor");
        code.add("    constexpr static int N = 20000;       // samples for convergence tests");
        code.add("    constexpr static int L = 8;           // levels for convergence tests");
        code.add("};");

        return code;
    }

    protected String constantToString(StringVariable constant, String type) {
        return "    constexpr static " + super.constantToString(constant, type);
    }

    public List<String> getModelParams() {
        List<String> code = new ArrayList<>();

        code.add("struct _modelParams {");
        code.addAll(getHeaderConstants(false));
//        code.add("    constexpr static float K   = 100.0f;  // Strike price");
//        code.add("    constexpr static float X0  = 100.0f;  // Initial price");
//        code.add("    constexpr static float T   = 2.0f;    // Expiry in years");
//        code.add("    constexpr static float r   = 0.05f;   // risk free interest");
//        code.add("    constexpr static float sig = 0.3f;    // the standard deviation of the stock's returns");
        code.add("};");

        return code;
    }

    public List<String> getRandomSource(boolean fast) {
        List<String> code = new ArrayList<>();

        code.add("static std::random_device rd;");
        code.add("static std::mt19937 gen(rd());");
        code.add("static std::normal_distribution<> randomGen(0, 1);");

        return code;
    }

    public List<String> getState() {
        List<String> code = new ArrayList<>();

        code.add("struct state {");

        stateVariables.stream()
                .forEach(variable -> {
                    code.add(String.format("    float %s_hf;", variable.name));
                    code.add(String.format("    float %s_hc;", variable.name));
                    code.add(String.format("    %s %s_xf;", typeToHeaderType(variable.type), variable.name));
                    code.add(String.format("    %s %s_xc;", typeToHeaderType(variable.type), variable.name));
                });

        headerRandomSources.stream()
                .forEach(source -> code.add(String.format("    %s %s_f[2];", typeToHeaderType(Type.fromRandomSet(source.set)), source.name)));

        code.add("");
        code.add("    state(int nf, int nc) {");
        stateVariables.stream()
                .forEach(variable -> {
                    code.add(String.format("        %s_hf = _modelParams::T / ((float) nf);", variable.name));
                    code.add(String.format("        %s_hc = _modelParams::T / ((float) nc);", variable.name));
                });
        code.add("    }");
        code.add("");
        code.add("    void nextSample() {");

        stateVariables.stream()
                .forEach(variable -> {
                    code.add(String.format("        %s_xf = %s;", variable.name, variable.initialValue));
                    code.add(String.format("        %s_xc = %s;", variable.name, variable.initialValue));
                });

        code.add("    }");
        code.add("");
        code.add("    void baseUpdate() {");

        stateVariables.stream()
                .forEach(variable -> {
                    code.add(String.format("        dWf[0] = sqrt(%s_hf)*randomGen(gen);", variable.name));
                    code.add(String.format("        %1$s_xf = stateUpdate(%1$s_xf, %1$s_hf, dWf[0]);", variable.name));
                });

        code.add("    }");
        code.add("");
        code.add("    void levelUpdate() {");

        stateVariables.stream()
                .forEach(variable -> {
                    code.add(String.format("        dWf[0] = sqrt(%s_hf)*randomGen(gen);", variable.name));
                    code.add(String.format("        dWf[1] = sqrt(%s_hf)*randomGen(gen);", variable.name));
                    code.add("");
                    code.add("        for (int m=0; m<2; m++) {");
                    code.add(String.format("            %1$s_xf = stateUpdate(%1$s_xf, %1$s_hf, dWf[m]);", variable.name));
                    code.add("        }");
                    code.add("");
                    code.add("        float dWc = dWf[0] + dWf[1];");
                    code.add("");
                    code.add(String.format("        %1$s_xc = stateUpdate(%1$s_xc, %1$s_hc, dWc);", variable.name));
                });

        code.add("    }");
        code.add("");
        code.add("    float stateUpdate(float previous, float h, float dW) {");
        code.add("        return previous + _modelParams::r*previous*h + _modelParams::sig*previous*dW");
        code.add("            + 0.5f*_modelParams::sig*_modelParams::sig*previous*(dW*dW-h);");
        code.add("    }");
        code.add("");
        code.add("    float payoffFine() {");
        code.add(String.format("        return %s;", ((StateVariableCode)payoff).asFine()));
        code.add("    }");
        code.add("");
        code.add("    float payoffCoarse() {");
        code.add(String.format("        return %s;", ((StateVariableCode)payoff).asCoarse()));
        code.add("    }");
        code.add("};");

        return code;
    }

    public List<String> getGenerated() {
        List<String> completeHeader = new ArrayList<>();

        completeHeader.add("#ifndef CPP_MLMC_GENERATED_H");
        completeHeader.add("#define CPP_MLMC_GENERATED_H");
        completeHeader.add("");
        completeHeader.add("#include <random>");
        completeHeader.add("");

        completeHeader.addAll(getMultilevel());
        completeHeader.add("");

        completeHeader.addAll(getRegression());
        completeHeader.add("");

        completeHeader.addAll(getModelParams());
        completeHeader.add("");

        //todo flag
        completeHeader.addAll(getRandomSource(false));
        completeHeader.add("");

        completeHeader.addAll(getState());
        completeHeader.add("");

        completeHeader.add("#endif //CPP_MLMC_GENERATED_H");

        return completeHeader;
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

    @Override
    public String toString() {
        JSONObject json = new JSONObject();

        json.put("generated", getGenerated());

        return json.toString();
    }
}
