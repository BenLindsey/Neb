package com.neb.openCL;

import com.neb.common.ProgramFactory;
import com.neb.common.CodeGenVisitor;
import com.neb.NebBaseVisitor;
import com.neb.common.VariableTable;
import com.neb.common.codes.ICode;

/**
 * Created by Ben on 21/11/2015.
 */

public class OpenCLProgramVisitor extends CodeGenVisitor<OpenCLProgram> {
    @Override
    protected ProgramFactory<OpenCLProgram> setFactory() {
        return new OpenCLFactory();
    }

    @Override
    protected NebBaseVisitor<ICode> newUpdateVisitor(VariableTable table) {
        return new OpenCLFunctionVisitor(table);
    }

    @Override
    protected NebBaseVisitor<ICode> newPayoffVisitor(VariableTable table) {
        throw new RuntimeException("Payoff unsupported for non-multilevel");
    }
}
