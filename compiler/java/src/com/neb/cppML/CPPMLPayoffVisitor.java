package com.neb.cppML;

import com.neb.NebParser;
import com.neb.common.VariableTable;
import com.neb.common.codes.ICode;
import com.neb.common.codes.StateVariableCode;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPMLPayoffVisitor extends CPPMLFunctionVisitor {
    public CPPMLPayoffVisitor(VariableTable table) {
        super(table);
    }

    @Override
    public ICode visitIndexedVariable(NebParser.IndexedVariableContext ctx) {
        return new StateVariableCode(super.visitIndexedVariable(ctx).toString());
    }
}
