package com.neb.cpp;

import com.neb.common.CodeGenVisitor;
import com.neb.NebBaseVisitor;
import com.neb.common.ProgramFactory;
import com.neb.common.codes.ICode;
import com.neb.common.codes.TreeCode;
import com.neb.common.VariableTable;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPProgramVisitor extends CodeGenVisitor<CPPProgram> {
    @Override
    protected ProgramFactory<CPPProgram> setFactory() {
        return new CPPFactory();
    }

    @Override
    protected NebBaseVisitor<ICode> newUpdateVisitor(VariableTable table) {
        return new CPPFunctionVisitor(table);
    }

    @Override
    protected NebBaseVisitor<ICode> newPayoffVisitor(VariableTable table) {
        throw new RuntimeException("Payoff unsupported for non-multilevel");
    }
}