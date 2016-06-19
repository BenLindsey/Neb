package com.neb.maxeler;

import com.neb.common.*;
import com.neb.common.codes.ICode;
import com.neb.common.codes.TreeCode;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by benlindsey on 09/02/2016.
 */
public class MaxelerProgram extends TreeProgram {

    public List<String> getC(boolean timeOnly, boolean fast) {
        List<String> code = new ArrayList<>();

        code.add("#include <math.h>");
        code.add("#include <stdio.h>");
        code.add("#include <stdlib.h>");
        code.add("#include <random>");
        code.add("#include <chrono>");
        code.add("#include <ctime>");
        code.add("#include \"Maxfiles.h\"");
        code.add("#include \"MaxSLiCInterface.h\"");
        code.add("");

        if(timeOnly) {
            code.add("#define TIMEONLY");
        }

        code.add(String.format("const int Simulations = %d;", getSimulations()));
        code.add(String.format("const int Steps = %d;", getSteps()));

        code.addAll(getRandomSource(fast));
        code.add("");

        code.addAll(getResultHandler());
        code.add("");

        code.add("int main(void)");
        code.add("{");

        code.add("  std::chrono::time_point<std::chrono::system_clock> _startTime, _endTime, _setupTime;");
        code.add("  _startTime = std::chrono::system_clock::now();");

        for (StringRandomSource source : headerRandomSources) {
            code.add(String.format("  int %sSize = sizeof(%s) * Simulations * Steps;",
                    source.name, typeToHeaderType(Type.fromRandomSet(source.set))));

            code.add(String.format("  %1$s* %2$s = (%1$s*)malloc(%2$sSize);",
                    typeToHeaderType(Type.fromRandomSet(source.set)), source.name));
        }
        code.add("");

        String randomSources = String.join(", ", headerRandomSources.stream()
                .map(source -> source.name).collect(Collectors.toList()));

        code.add(String.format("  generateInput(%s);", randomSources));
        code.add("");
        code.add("  int outputSize = sizeof(float) * Simulations * Steps;");
        code.add("  float* output = (float*)malloc(outputSize);");
        code.add("");

        code.add("  _setupTime = std::chrono::system_clock::now();");

        code.add(String.format("  NebStream(%s, output);", randomSources));
        code.add("");

        code.add("  _endTime = std::chrono::system_clock::now();");
        code.add("");

        code.add("  std::chrono::duration<double> total_seconds = _endTime - _startTime;");
        code.add("  std::chrono::duration<double> setup_seconds = _setupTime - _startTime;");
        code.add("  std::chrono::duration<double> run_seconds = _endTime - _setupTime;");
        code.add("  logResult(output, Steps, Simulations, total_seconds.count(), setup_seconds.count(), run_seconds.count());");
        code.add("");

        code.add("  return 0;");
        code.add("}");

        return code;
    }

    private List<String> getResultHandler() {
        List<String> code = new ArrayList<>();

        code.add("void logResult(float* result, int width, int height, double totalTime, double setupTime, double runTime)");
        code.add("{");
        code.add("    printf(\"{\\n\");");

        code.add("    printf(\"  \\\"totalTime\\\": %f,\\n\", totalTime);");
        code.add("    printf(\"  \\\"setupTime\\\": %f,\\n\", setupTime);");
        code.add("    printf(\"  \\\"runTime\\\": %f,\\n\", runTime);");


        code.add("    #ifndef TIMEONLY");
        code.add("    for (int i = 0; i < width * height; i++)");
        code.add("    {");
        code.add("        if (i % width == 0) {");
        code.add("            printf(\"  \\\"simulation_%d\\\": [\\n\", i / width);");
        code.add("            printf(\"    %f,\\n\", (float)OUTPUT_INITIAL);");
        code.add("        }");

        code.add("       printf(\"    %f%s\", result[i], ((i + 1) % width == 0) ?");
        code.add("                (i + 1 == width * height) ? \"\\n  ]\\n\" : \"\\n  ],\\n\" : \",\\n\");");
        code.add("    }");

        code.add("    #endif");
        code.add("    printf(\"}\\n\");");
        code.add("}");


        return code;
    }

    public List<String> getKernel() {
        List<String> code = new ArrayList<>();

        code.add("package nebstream;");
        code.add("");
        code.addAll(getKernelImports());
        code.add("");
        code.add("class NebStreamKernel extends Kernel {");
        code.add("");

        List<String> scalars = constants.stream()
                .filter(constant -> !Type.isArray(constant.type))
                .map(this::constantToString).collect(Collectors.toList());

        code.addAll(scalars);

        if(scalars.size() > 0) {
            code.add("");
        }

        code.add("  NebStreamKernel(KernelParameters parameters) {");
        code.add("    super(parameters);");
        code.add("");

        List<List<String>> tables = constants.stream()
                .filter(constant -> Type.isArray(constant.type))
                .map(this::constantToTable)
                .collect(Collectors.toList());

        tables.forEach(code::addAll);

        if(tables.size() > 0) {
            code.add("");
        }

        code.add("    OffsetExpr loopLength = stream.makeOffsetAutoLoop(\"loopLength\");");
        code.add("    DFEVar loopLengthVal = loopLength.getDFEVar(this, dfeUInt(8));");
        code.add("");

        code.add("    CounterChain chain = control.count.makeCounterChain();");
        code.add("    DFEVar y = chain.addCounter(Steps, 1);");
        code.add("    DFEVar x = chain.addCounter(Simulations, 1);");
        code.add("    DFEVar loopCounter = chain.addCounter(loopLengthVal, 1);");
        code.add("    DFEVar yWrap = y.cast(dfeUInt(2));");
        code.add("");


        headerRandomSources.stream().forEach(source -> {
            code.add(String.format("    DFEVar %1$s = io.input(\"%1$s\", %2$s, loopCounter === (loopLengthVal-1));", source.name, typeToDFEType(Type.fromRandomSet(source.set))));
        });
        code.add("");

        stateVariables.stream().forEach(variable ->  {
            code.add(String.format("    DFEVar %sCarried = %s.newInstance(this);", variable.name, typeToDFEType(variable.type)));
            code.add(String.format("    DFEVar %1$s = y === 0 ? %2$s : %1$sCarried;", variable.name, variable.initialValue));
        });

        code.add("");

        stateVariables.stream().forEach(variable -> {
            code.add(String.format("    DFEVar %sTemp = %s;", variable.name, updateFunctions.get(variable.name)));
        });

        code.add("");

        stateVariables.stream().forEach(variable -> {
            code.add(String.format("    %1$s = %1$sTemp;", variable.name));
            code.add(String.format("    %1$sCarried <== stream.offset(%1$s, -(Simulations * loopLength));", variable.name));
        });

        code.add("");

        code.add(String.format("    io.output(\"output\", %1$s, %1$s.getType(), loopCounter === (loopLengthVal-1));", output));
        code.add("  }");

        code.add("}");

        return code;
    }

    public List<String> getManager() {
        List<String> code = new ArrayList<>();

        code.add("package nebstream;");
        code.add("");
        code.addAll(getManagerImports());
        code.add("");
        code.add("public class NebStreamManager {");
        code.add("");
        code.add("  private static final String s_kernelName = \"NebStreamKernel\";");
        code.add(String.format("  private static final int Simulations = %s;", getSimulations()));
        code.add(String.format("  private static final int Steps = %s;", getSteps()));
        code.add("");

        code.add("  public static void main(String[] args) {");
        code.add("    NebStreamEngineParameters params = new NebStreamEngineParameters(args);");
        code.add("    Manager manager = new Manager(params);");
        code.add("    Kernel kernel = new NebStreamKernel(manager.makeKernelParameters(s_kernelName));");
        code.add("    manager.setKernel(kernel);");
        code.add("    manager.setIO(");

        headerRandomSources.stream().forEach(source -> {
            code.add(String.format("      link(\"%s\", IODestination.CPU),", source.name));
        });

        code.add("      link(\"output\", IODestination.CPU));");
        code.add("");
        code.add("    manager.createSLiCinterface(interfaceDefault());");
        code.add("");
        code.add("    configBuild(manager, params);");
        code.add("");
        code.add("    manager.build();");
        code.add("  }");
        code.add("");
        code.add("  private static EngineInterface interfaceDefault() {");
        code.add("    EngineInterface engine_interface = new EngineInterface();");
        code.add(String.format("    CPUTypes type = %s;", typeToEngineType(Type.REAL))); //todo type
        code.add("    int size = type.sizeInBytes();");
        code.add("");
        code.add("    InterfaceParam loopLength = engine_interface.getAutoLoopOffset(s_kernelName, \"loopLength\");");
        code.add("    engine_interface.setTicks(s_kernelName, Simulations * Steps * loopLength);");
        code.add("");

        headerRandomSources.stream().forEach(source -> {
            code.add(String.format("    engine_interface.setStream(\"%1$s\", %2$s, Simulations * Steps * %2$s.sizeInBytes());", source.name, typeToEngineType(Type.fromRandomSet(source.set))));
        });

        code.add("    engine_interface.setStream(\"output\", type, Simulations * Steps * size);");
        code.add("");
        code.add("    engine_interface.ignoreAutoLoopOffset(s_kernelName, \"loopLength\");");
        code.add("");
        code.add("    return engine_interface;");
        code.add("  }");
        code.add("");

        code.add("  private static void configBuild(Manager manager, NebStreamEngineParameters params) {");
        code.add("    manager.setEnableStreamStatusBlocks(false);");
        code.add("    BuildConfig buildConfig = manager.getBuildConfig();");
        code.add("    buildConfig.setMPPRCostTableSearchRange(params.getMPPRStartCT(), params.getMPPREndCT());");
        code.add("    buildConfig.setMPPRParallelism(params.getMPPRThreads());");
        code.add("    buildConfig.setMPPRRetryNearMissesThreshold(params.getMPPRRetryThreshold());");
        code.add("  }");
        code.add("}");

        return code;
    }

    public Collection<String> getKernelImports() {
        return Arrays.asList(
                "import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.KernelParameters;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.KernelMath;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.core.CounterChain;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.core.Stream.OffsetExpr;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.stdlib.memory.Memory;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEType;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar;"
        );
    }

    public Collection<String> getManagerImports() {
        return Arrays.asList(
                "import static com.maxeler.maxcompiler.v2.managers.standard.Manager.link;",
                "import com.maxeler.maxcompiler.v2.kernelcompiler.Kernel;",
                "import com.maxeler.maxcompiler.v2.managers.BuildConfig;",
                "import com.maxeler.maxcompiler.v2.managers.engine_interfaces.CPUTypes;",
                "import com.maxeler.maxcompiler.v2.managers.engine_interfaces.EngineInterface;",
                "import com.maxeler.maxcompiler.v2.managers.engine_interfaces.InterfaceParam;",
                "import com.maxeler.maxcompiler.v2.managers.standard.IOLink.IODestination;",
                "import com.maxeler.maxcompiler.v2.managers.standard.Manager;"
        );
    }

    public MaxelerProgram merge(MaxelerProgram nextResult) {
        super.merge(nextResult);

        return this;
    }

    public MaxelerProgram addUpdateFunction(String name, TreeCode update) {
        super.addUpdateFunction(name, update);

        return this;
    }

    public MaxelerProgram addStateVariable(StringVariable variable) {
        super.addStateVariable(variable);

        return this;
    }

    public MaxelerProgram addRandomSource(StringRandomSource randomSource) {
        super.addRandomSource(randomSource);

        return this;
    }

    public MaxelerProgram addConstant(StringVariable constant) {
        super.addConstant(constant);

        return this;
    }

    public MaxelerProgram setOutputValue(String name) {
        super.setOutputValue(name);

        return this;
    }

    public MaxelerProgram setPayoff(ICode payoff) {
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
                throw new RuntimeException("Unknown type, cannot convert to java type");
        }
    }

    private String typeToDFEType(Type type) {
        switch (type) {
            case INT:
            case INT_ARRAY:
                return "dfeInt(32)";
            case REAL:
            case REAL_ARRAY:
                return "dfeFloat(8, 24)";
            default:
                throw new RuntimeException("Unknown type, cannot convert to maxeler type");
        }
    }

    private String typeToEngineType(Type type) {
        switch (type) {
            case INT:
            case INT_ARRAY:
                return "CPUTypes.INT32";
            case REAL:
            case REAL_ARRAY:
                return "CPUTypes.FLOAT";
            default:
                throw new RuntimeException("Unknown type, cannot convert to maxeler type");
        }

    }

    protected String constantToString(StringVariable constant) {
        if(constant.name.equals("Simulations") || constant.name.equals("Steps")) {
            return String.format("  private static final int %s = %s;", constant.name, constant.initialValue);
        }

        return String.format("  private final DFEVar %s = constant.var(%s).cast(%s);", constant.name, constant.initialValue, typeToDFEType(constant.type));
    }

    protected List<String> constantToTable(StringVariable constant) {
        return Arrays.asList(
                String.format("    Memory<DFEVar> %s = mem.alloc(%s, %s);", constant.name, typeToDFEType(constant.type), constant.elements),
                String.format("    %s.setContents(%s);", constant.name, arrayToInline(constant))
        );
    }

    private String arrayToInline(StringVariable constant) {
        return String.format("new double[] %s", constant.initialValue);
    }

    @Override
    public String toString() {
        JSONObject json = new JSONObject();

        json.put("c", getC(false, false));
        json.put("kernel", getKernel());
        json.put("manager", getManager());

        return json.toString();
    }
}
