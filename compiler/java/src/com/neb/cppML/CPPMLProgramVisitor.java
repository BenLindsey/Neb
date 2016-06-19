package com.neb.cppML;

import com.neb.NebBaseVisitor;
import com.neb.common.CodeGenVisitor;
import com.neb.common.ProgramFactory;
import com.neb.common.VariableTable;
import com.neb.common.codes.ICode;
import com.neb.common.codes.StateVariableCode;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPMLProgramVisitor extends CodeGenVisitor<CPPMLProgram> {
    @Override
    protected ProgramFactory<CPPMLProgram> setFactory() {
        return new CPPMLFactory();
    }

    @Override
    protected NebBaseVisitor<ICode> newUpdateVisitor(VariableTable table) {
        return new CPPMLFunctionVisitor(table);
    }

    @Override
    protected NebBaseVisitor<ICode> newPayoffVisitor(VariableTable table) {
        return new CPPMLPayoffVisitor(table);
    }
}