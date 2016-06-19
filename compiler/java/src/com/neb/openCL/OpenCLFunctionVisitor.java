package com.neb.openCL;

import com.neb.common.ProgramFactory;
import com.neb.common.FunctionVisitor;
import com.neb.common.VariableTable;

/**
 * Created by Ben on 05/12/2015.
 */
public class OpenCLFunctionVisitor extends FunctionVisitor<OpenCLProgram> {
    public OpenCLFunctionVisitor(VariableTable table) {
        super(table);
    }

    @Override
    protected ProgramFactory<OpenCLProgram> getFactory() {
        return new OpenCLFactory();
    }
}
