package com.neb.ad;

import com.neb.NebBaseVisitor;
import com.neb.NebParser;
import com.neb.common.CodeGenVisitor;
import com.neb.common.ProgramFactory;
import com.neb.common.VariableTable;
import com.neb.common.codes.ICode;
import com.neb.cpp.CPPFactory;
import com.neb.cpp.CPPFunctionVisitor;
import com.neb.cpp.CPPProgram;

/**
 * Created by Ben on 23/01/2016.
 */
public class ADProgramVisitor extends CodeGenVisitor<ADProgram> {
    @Override
    protected ProgramFactory<ADProgram> setFactory() {
        return new ADFactory();
    }

    @Override
    protected NebBaseVisitor<ICode> newUpdateVisitor(VariableTable table) {
        return new ADFunctionVisitor(table);
    }

    @Override
    protected NebBaseVisitor<ICode> newPayoffVisitor(VariableTable table) {
        throw new RuntimeException("Payoff unsupported for non-multilevel");
    }

    @Override
    public ADProgram visitSensitivityFunction(NebParser.SensitivityFunctionContext ctx) {
        String function = ctx.function.getText();
        String variable = ctx.variable.getText();

        return new ADProgram().addSensitivity(function, variable);
    }
}