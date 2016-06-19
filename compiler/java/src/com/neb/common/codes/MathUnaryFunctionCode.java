package com.neb.common.codes;

/**
 * Created by Ben on 05/12/2015.
 */
public class MathUnaryFunctionCode extends TreeCode {
    ICode operator;
    ICode child;

    public MathUnaryFunctionCode(ICode operator, ICode child) {
        super(operator, new TreeCode("("), child, new TreeCode(")"));
        this.operator = operator;
        this.child = child;
    }

    @Override
    public Boolean isUnaryFunction() {
        return true;
    }

    public ICode getChild() {
        return child;
    }
}
