package com.neb.maxeler;

import com.neb.NebBaseVisitor;
import com.neb.common.CodeGenVisitor;
import com.neb.common.ProgramFactory;
import com.neb.common.VariableTable;
import com.neb.common.codes.ICode;

/**
 * Created by benlindsey on 09/02/2016.
 */
public class MaxelerProgramVisitor extends CodeGenVisitor<MaxelerProgram> {

    @Override
    protected ProgramFactory<MaxelerProgram> setFactory() {
        return new MaxelerFactory();
    }

    @Override
    protected NebBaseVisitor<ICode> newUpdateVisitor(VariableTable table) {
        return new MaxelerFunctionVisitor(table);
    }

    @Override
    protected NebBaseVisitor<ICode> newPayoffVisitor(VariableTable table) {
        throw new RuntimeException("Payoff unsupported for non-multilevel");
    }
}
