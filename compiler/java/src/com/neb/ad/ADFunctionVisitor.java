package com.neb.ad;

import com.neb.NebParser;
import com.neb.common.FunctionVisitor;
import com.neb.common.ProgramFactory;
import com.neb.common.VariableTable;
import com.neb.common.codes.ICode;
import com.neb.common.codes.TreeCode;
import com.neb.cpp.CPPFactory;
import com.neb.cpp.CPPProgram;

/**
 * Created by Ben on 23/01/2016.
 */
public class ADFunctionVisitor extends FunctionVisitor<ADProgram> {
    public ADFunctionVisitor(VariableTable table) {
        super(table);
    }

    @Override
    protected ProgramFactory<ADProgram> getFactory() {
        return new ADFactory();
    }
}
