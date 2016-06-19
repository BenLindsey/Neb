package com.neb.cppML;

import com.neb.common.CUtils;
import com.neb.common.TreeFactory;
import com.neb.common.codes.ICode;
import com.neb.common.codes.StateVariableCode;

import java.util.List;

/**
 * Created by Ben on 23/01/2016.
 */
public class CPPMLFactory extends TreeFactory<CPPMLProgram> {
    @Override
    public CPPMLProgram aggregateProgram(CPPMLProgram aggregate, CPPMLProgram nextResult) {
        return aggregate.merge(nextResult);
    }

    @Override
    public CPPMLProgram defaultProgram() {
        return new CPPMLProgram();
    }


    @Override
    public ICode referenceParameter(String name) {
        return new StateVariableCode(String.format("_modelParams::%s", name));
    }

    @Override
    public ICode mathFunction(String text) {
        return codeFromString(CUtils.floatFunction(text));
    }

    @Override
    public ICode referenceOther(String name) {
        return new StateVariableCode(name);
    }
}
