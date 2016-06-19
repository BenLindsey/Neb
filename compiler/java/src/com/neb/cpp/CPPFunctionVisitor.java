package com.neb.cpp;

import com.neb.common.ProgramFactory;
import com.neb.common.FunctionVisitor;
import com.neb.common.codes.ICode;
import com.neb.common.codes.TreeCode;
import com.neb.common.VariableTable;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPFunctionVisitor extends FunctionVisitor<CPPProgram> {
    public CPPFunctionVisitor(VariableTable table) {
        super(table);
    }

    @Override
    protected ProgramFactory<CPPProgram> getFactory() {
        return new CPPFactory();
    }
}
