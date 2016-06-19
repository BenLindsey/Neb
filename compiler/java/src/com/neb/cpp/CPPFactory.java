package com.neb.cpp;

import com.neb.common.codes.ICode;
import com.neb.common.codes.TreeCode;
import com.neb.common.TreeFactory;

import java.util.List;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPFactory extends TreeFactory<CPPProgram> {
    @Override
    public CPPProgram aggregateProgram(CPPProgram aggregate, CPPProgram nextResult) {
        return aggregate.merge(nextResult);
    }

    @Override
    public CPPProgram defaultProgram() {
        return new CPPProgram();
    }
}
