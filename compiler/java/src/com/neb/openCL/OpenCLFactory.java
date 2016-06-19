package com.neb.openCL;

import com.neb.common.TreeFactory;
import com.neb.common.codes.ICode;
import com.neb.common.codes.TreeCode;

import java.util.List;

/**
 * Created by Ben on 21/11/2015.
 */
public class OpenCLFactory extends TreeFactory<OpenCLProgram> {
    @Override
    public OpenCLProgram aggregateProgram(OpenCLProgram aggregate, OpenCLProgram nextResult) {
        return aggregate.merge(nextResult);
    }

    @Override
    public OpenCLProgram defaultProgram() {
        return new OpenCLProgram();
    }
}
