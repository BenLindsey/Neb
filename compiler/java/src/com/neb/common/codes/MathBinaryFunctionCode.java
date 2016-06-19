package com.neb.common.codes;

/**
 * Created by Ben on 05/12/2015.
 */
public class MathBinaryFunctionCode extends TreeCode {
    private final ICode operator;
    private final ICode left;
    private final ICode right;

    public MathBinaryFunctionCode(ICode operator, ICode left, ICode right) {
        super(operator, new TreeCode("("), left, new TreeCode(", "), right, new TreeCode(")"));
        this.operator = operator;
        this.left = left;
        this.right = right;
    }

    @Override
    public Boolean isBinaryFunction() {
        return true;
    }
}
