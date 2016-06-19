package com.neb.cppML;

import com.neb.common.ProgramFactory;
import com.neb.common.FunctionVisitor;
import com.neb.common.VariableTable;
import com.neb.common.codes.StateVariableCode;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPMLFunctionVisitor extends FunctionVisitor<CPPMLProgram> {
    public CPPMLFunctionVisitor(VariableTable table) {
        super(table);
    }

    @Override
    protected ProgramFactory<CPPMLProgram> getFactory() {
        return new CPPMLFactory();
    }
}
