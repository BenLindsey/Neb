package com.neb.ad;

import com.neb.Main;
import com.neb.common.TreeFactory;
import com.neb.common.codes.ArrayReferenceCode;
import com.neb.common.codes.ICode;
import com.neb.cpp.CPPProgram;

/**
 * Created by Ben on 23/01/2016.
 */
public class ADFactory extends TreeFactory<ADProgram> {
    @Override
    public ADProgram aggregateProgram(ADProgram aggregate, ADProgram nextResult) {
        return aggregate.merge(nextResult);
    }

    @Override
    public ADProgram defaultProgram() {
        return new ADProgram();
    }

    @Override
    public ICode referenceRandomSource(String name) {
        return codeFromString(String.format("%s", name));
    }

    @Override
    public ICode referenceArray(String name) {
        return new ArrayReferenceCode(name + "[0]");
    }
}
