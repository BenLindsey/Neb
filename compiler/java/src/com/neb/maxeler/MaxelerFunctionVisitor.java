package com.neb.maxeler;

import com.neb.common.ProgramFactory;
import com.neb.common.FunctionVisitor;
import com.neb.common.VariableTable;

public class MaxelerFunctionVisitor extends FunctionVisitor<MaxelerProgram> {
    public MaxelerFunctionVisitor(VariableTable table) {
        super(table);
    }

    @Override
    protected ProgramFactory<MaxelerProgram> getFactory() {
        return new MaxelerFactory();
    }
}
