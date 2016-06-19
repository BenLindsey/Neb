package com.neb.common;

import com.neb.NebBaseVisitor;
import com.neb.NebParser;

/**
 * Created by Ben on 05/12/2015.
 */
public class TypeVisitor extends NebBaseVisitor<Type> {
    private VariableTable table;

    public TypeVisitor(VariableTable table) {
        this.table = table;
    }

    @Override
    protected Type defaultResult() {
        return Type.INT;
    }

    @Override
    protected Type aggregateResult(Type aggregate, Type nextResult) {
        return (aggregate.equals(Type.REAL) || nextResult.equals(Type.REAL)) ? Type.REAL : Type.INT;
    }

    @Override
    public Type visitNumberExpr(NebParser.NumberExprContext ctx) {
        return Type.getFromNumberExpr(ctx);
    }

    @Override
    public Type visitIndexedVariable(NebParser.IndexedVariableContext ctx) {
        String name = ctx.name.getText();

        return table.getType(name);
    }
}
