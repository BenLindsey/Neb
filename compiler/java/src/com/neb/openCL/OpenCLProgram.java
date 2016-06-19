package com.neb.openCL;

import com.neb.common.StringRandomSource;
import com.neb.common.StringVariable;
import com.neb.common.TreeProgram;
import com.neb.common.Type;
import com.neb.common.codes.ICode;
import org.json.JSONObject;

import java.util.*;
import java.util.stream.Collectors;

/**
 * Created by Ben on 21/11/2015.
 */
public class OpenCLProgram extends TreeProgram {
    private List<String> getKernelConstants() {
        return constants.stream()
                .map(constant -> String.format("__constant %s", constantToString(constant, typeToKernelType(constant.type)))  )
                .collect(Collectors.toList());
    }

    private List<String> getUpdateFunctions() {
        List<String> code = new ArrayList<>();

        List<String> args = getKernelArguments();

        code.add(String.format("\n__kernel void Add(%s) {",  String.join(", ", args)));
        code.add("  const int currentHeight = get_global_id(1);");
        code.add("  const int width = get_global_size(1);");
        code.add("");

        stateVariables.stream().forEach(variable ->
                code.add(String.format("  %s %s = %s;",
                        typeToKernelType(variable.type), variable.name, variable.initialValue)));

        code.add("");
        code.add("  for(int i = 0; i < Steps; i++) {");
        code.add("    const int id = currentHeight * Steps + i;\n");

        getCommonSubExpressions().stream().forEach(line -> code.add(String.format("    %s", line)));

        stateVariables.stream().forEach(variable ->
                code.add(String.format("    %s %sTemp = %s;",
                        typeToKernelType(variable.type), variable.name, updateFunctions.get(variable.name))));

        code.add("");

        stateVariables.stream().forEach(variable ->
                code.add(String.format("    %1$s = %1$sTemp;", variable.name)));

        code.add(String.format("\n    output[id] = %s;", output));

        code.add("  }");
        code.add("}");

        return code;
    }

    private List<String> getKernelArguments() {
        List<String> args = headerRandomSources.stream()
                .map(source -> String.format("__global %s* %s",
                        typeToKernelType(Type.fromRandomSet(source.set)), source.name))
                .collect(Collectors.toList());

        args.add("__global float* output");

        return args;
    }

    public List<String> getHeader(boolean timeOnly, boolean fast) {
        List<String> completeHeader = new ArrayList<>();

        completeHeader.add("#include <stdlib.h>");
        completeHeader.add("#include <random>");

        if(timeOnly) {
            completeHeader.add("#define TIMEONLY");
        }

        completeHeader.addAll(getHeaderConstants());
        completeHeader.addAll(getRandomSource(fast));
        completeHeader.addAll(getMacros());

        return completeHeader;
    }

    public List<String> getKernel() {
        List<String> completeKernel = new ArrayList<>();

        completeKernel.addAll(getKernelConstants());
        completeKernel.addAll(getUpdateFunctions());

        return completeKernel;
    }

    public List<String> getMacros() {
        List<String> macros = new ArrayList<>();

        macros.add(String.format("\n#define INPUTS_MEM %s",
                String.join("", headerRandomSources.stream()
                        .map(source -> String.format("cl_mem %s; ", source.name))
                        .collect(Collectors.toList()))));

        macros.add("");

        macros.add(String.format("#define INPUTS_INIT %s",
                String.join("", headerRandomSources.stream()
                        .map(source -> String.format("%s(NULL), ", source.name))
                        .collect(Collectors.toList()))));

        macros.add("");

        macros.add(String.format("#define INPUTS_ARGS %s",
                String.join("", headerRandomSources.stream()
                        .map(source -> String.format("%s* %s, ", typeToHeaderType(Type.fromRandomSet(source.set)), source.name))
                        .collect(Collectors.toList()))));

        macros.add("");

        for(int i = 0; i < headerRandomSources.size(); i++) {
            StringRandomSource source = headerRandomSources.get(i);

            macros.add(String.format("%sif (%s) \\", i == 0 ? "#define INPUTS_RELEASE " : "", source.name));
            macros.add("{\\");
            macros.add(String.format("\terr = clReleaseMemObject(%s);\\", source.name));
            macros.add("\tif (CL_SUCCESS != err)\\");
            macros.add("\t{\\");
            macros.add("\t\tLogError(\"Error: clReleaseMemObject returned '%s'.\\n\", TranslateOpenCLError(err));\\");
            macros.add("\t}\\");
            macros.add(String.format("}%s", (i + 1) < headerRandomSources.size() ? "\\" : ""));
        }

        macros.add("");

        for(int i = 0; i < headerRandomSources.size(); i++) {
            StringRandomSource source = headerRandomSources.get(i);

            macros.add(String.format("%socl->%2$s = clCreateBuffer(ocl->context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, sizeof(%3$s) * arrayWidth * arrayHeight, %2$s, &err);\\", i == 0 ? "#define INPUTS_BUFFER " : "",
                    source.name, typeToHeaderType(Type.fromRandomSet(source.set))));
            macros.add("if (CL_SUCCESS != err)\\");
            macros.add("{\\");
            macros.add("\tLogError(\"Error: clCreateBuffer for srcA returned %s\\n\", TranslateOpenCLError(err));\\");
            macros.add("\treturn err;\\");
            macros.add(String.format("}%s", (i + 1) < headerRandomSources.size() ? "\\" : ""));
        }

        macros.add("");

        for(int i = 0; i <= headerRandomSources.size(); i++) {
            StringRandomSource source = i < headerRandomSources.size() ? headerRandomSources.get(i)
                    : new StringRandomSource("dstMem", null, null, null);

            macros.add(String.format("%serr = clSetKernelArg(ocl->kernel, %s, sizeof(cl_mem), (void *)&ocl->%s);\\",
                    i == 0 ? "#define INPUTS_SET " : "", i, source.name));
            macros.add("if (CL_SUCCESS != err)\\");
            macros.add("{\\");
            macros.add("\tLogError(\"error: Failed to set argument " + source.name + ", returned %s\\n\", TranslateOpenCLError(err));\\");
            macros.add("\treturn err;\\");
            macros.add(String.format("}%s", i < headerRandomSources.size() ? "\\" : ""));
        }

        macros.add("");

        for(int i = 0; i < headerRandomSources.size(); i++) {
            StringRandomSource source = headerRandomSources.get(i);

            macros.add(String.format("%scl_uint %sSize = sizeof(%s) * arrayWidth * arrayHeight;\\",
                    i == 0 ? "#define INPUTS_MALLOC " : "", source.name, typeToKernelType(Type.fromRandomSet(source.set))));

            macros.add(String.format("%1$s* %2$s = (%1$s*)malloc(%2$sSize);\\",
                    typeToKernelType(Type.fromRandomSet(source.set)), source.name));
        }

        macros.add("cl_uint dstSize = sizeof(float) * arrayWidth * arrayHeight;\\");
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

        macros.add(String.format("#define INPUTS_BUFFER_ARGS %s", String.join(", ", names)));

        macros.add("");

        macros.add(String.format("#define INPUTS_FREE %s", String.join(" ", names.stream()
                .map(name -> String.format("free(%s);", name))
                .collect(Collectors.toList()))));

        return macros;
    }

    public OpenCLProgram addUpdateFunction(String name, ICode update) {
        super.addUpdateFunction(name, update);

        return this;
    }

    public OpenCLProgram addStateVariable(StringVariable variable) {
        super.addStateVariable(variable);

        return this;
    }

    public OpenCLProgram addRandomSource(StringRandomSource randomSource) {
        super.addRandomSource(randomSource);

        return this;
    }

    public OpenCLProgram addConstant(StringVariable constant) {
        super.addConstant(constant);

        return this;
    }

    public OpenCLProgram merge(OpenCLProgram nextResult) {
        super.merge(nextResult);

        return this;
    }

    public OpenCLProgram setOutputValue(String name) {
        super.setOutputValue(name);

        return this;
    }


    public OpenCLProgram setPayoff(ICode payoff) {
        super.setPayoff(payoff);

        return this;
    }

    private String typeToKernelType(Type type) {
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
    protected String typeToHeaderType(Type type) {
        switch (type) {
            case INT:
            case INT_ARRAY:
                return "cl_int";
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

        json.put("header", getHeader(false, false));
        json.put("kernel", getKernel());

        return json.toString();
    }
}
