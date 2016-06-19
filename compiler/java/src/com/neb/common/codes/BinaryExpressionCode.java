package com.neb.common.codes;

/**
 * Created by Ben on 05/12/2015.
 */
public class BinaryExpressionCode extends TreeCode {
    ICode operator;
    ICode left;
    ICode right;

    public BinaryExpressionCode(ICode left, ICode operator, ICode right) {
        super(left, new TreeCode(" "), operator, new TreeCode(" "), right);
        this.left = left;
        this.operator = operator;
        this.right = right;
    }

    @Override
    public Boolean isBinaryExpression() {
        return true;
    }
}
