package com.neb;

import com.neb.ad.ADProgram;
import com.neb.ad.ADProgramVisitor;
import com.neb.common.Target;
import com.neb.cpp.CPPProgram;
import com.neb.cpp.CPPProgramVisitor;
import com.neb.cppML.CPPMLProgram;
import com.neb.cppML.CPPMLProgramVisitor;
import com.neb.maxeler.MaxelerProgram;
import com.neb.maxeler.MaxelerProgramVisitor;
import com.neb.openCL.OpenCLProgram;
import com.neb.openCL.OpenCLProgramVisitor;
import org.antlr.v4.gui.SystemFontMetrics;
import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.apache.commons.cli.*;

import java.io.*;
import java.util.List;

public class Main {

    public static boolean OPTIMISE_SUB_EXPRESSIONS = true;

    public static void main(String[] args) {
        CommandLineParser parser = new DefaultParser();

        try {
            CommandLine cmd = parser.parse(getOptions(), args);

            // C args
            String headerFile = cmd.getOptionValue("h", "MonteCarlo.h");
            String kernelFile = cmd.getOptionValue("k", "Template.cl");

            // Maxeler args
            String maxCFile = cmd.getOptionValue("mc", "NebStreamCpuCode.c");
            String maxKernelFile = cmd.getOptionValue("mk", "NebStreamKernel.maxj");
            String maxManagerFile = cmd.getOptionValue("mm", "NebStreamManager.maxj");

            //ML
            String generatedFile = cmd.getOptionValue("h", "generated.h");

            OPTIMISE_SUB_EXPRESSIONS = !cmd.hasOption("n");

            Target target = Target.fromString(cmd.getOptionValue("t", "opencl"));

            ANTLRInputStream input = new ANTLRInputStream(new FileInputStream(cmd.getOptionValue("m")));
            NebLexer lexer = new NebLexer(input);
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            NebParser nebParser = new NebParser(tokens);

            switch (target) {
                case CPP:
                    generateCPP(headerFile, nebParser, cmd.hasOption("o"), cmd.hasOption("f"));
                    break;
                case CPPML:
                    generateCPPML(generatedFile, nebParser);
                    break;
                case OpenCL:
                    generateOpenCL(headerFile, kernelFile, nebParser, cmd.hasOption("o"), cmd.hasOption("f"));
                    break;
                case Maxeler:
                    generateMaxeler(maxCFile, maxKernelFile, maxManagerFile, nebParser, cmd.hasOption("o"), cmd.hasOption("f"));
                    break;
                case AD:
                    OPTIMISE_SUB_EXPRESSIONS = false;
                    generateAD(headerFile, nebParser);
                    break;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static Options getOptions() {
        Options options = new Options();

        options.addOption("m", "model", true, "Model file location");
        options.addOption("h", "header", true, "Header file location");
        options.addOption("k", "kernel", true, "Kernel file location");
        options.addOption("t", "target", true, "OpenCL or CPP or Maxeler output");

        options.addOption("mc", "maxelerC", true, "Maxeler C file location");
        options.addOption("mk", "maxelerKernel", true, "Maxeler Kernel file location");
        options.addOption("mm", "maxelerManager", true, "Maxeler Manager");

        options.addOption("g", "generated", true, "CPPML Generator");

        options.addOption("o", "timeOnly", false, "Only print execution time");
        options.addOption("f", "fast", false, "use a fast random source");
        options.addOption("n", "noOptimisations", false, "Disable optimisations");

        return options;
    }

    public static void printFile(String name, List<String> lines) throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter(name, "UTF-8");
        lines.forEach(writer::println);
        writer.close();
    }

    private static void generateCPP(String headerFile, NebParser parser, boolean timeOnly, boolean fast) throws FileNotFoundException, UnsupportedEncodingException  {
        CPPProgramVisitor visitor = new CPPProgramVisitor();

        CPPProgram cpp = visitor.visit(parser.model());

        if(!timeOnly) {
            System.out.println(cpp);
        }

        printFile(headerFile, cpp.getHeader(timeOnly, fast));
    }


    private static void generateAD(String headerFile, NebParser parser) throws FileNotFoundException, UnsupportedEncodingException  {
        ADProgramVisitor visitor = new ADProgramVisitor();

        ADProgram ad = visitor.visit(parser.model());

        printFile(headerFile, ad.getHeader());
    }

    private static void generateCPPML(String headerFile, NebParser parser) throws FileNotFoundException, UnsupportedEncodingException  {
        CPPMLProgramVisitor visitor = new CPPMLProgramVisitor();

        CPPMLProgram cpp = visitor.visit(parser.model());

        System.out.println(cpp);

        printFile(headerFile, cpp.getGenerated());
    }

    private static void generateOpenCL(String headerFile, String kernelFile, NebParser parser, boolean timeOnly, boolean fast) throws FileNotFoundException, UnsupportedEncodingException {
        OpenCLProgramVisitor visitor = new OpenCLProgramVisitor();

        OpenCLProgram openCL = visitor.visit(parser.model());

        if(!timeOnly) {
            System.out.println(openCL);
        }

        printFile(headerFile, openCL.getHeader(timeOnly, fast));
        printFile(kernelFile, openCL.getKernel());
    }

    private static void generateMaxeler(String maxCFile, String maxKernelFile, String maxManagerFile, NebParser parser, boolean timeOnly, boolean fast) throws FileNotFoundException, UnsupportedEncodingException {
        MaxelerProgramVisitor visitor = new MaxelerProgramVisitor();

        MaxelerProgram max = visitor.visit(parser.model());

        if(!timeOnly) {
            System.out.println(max);
        }

        printFile(maxCFile, max.getC(timeOnly, fast));
        printFile(maxKernelFile, max.getKernel());
        printFile(maxManagerFile, max.getManager());
    }
}
