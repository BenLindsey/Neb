package com.neb.common;

import com.neb.*;
import com.neb.common.codes.ICode;
import org.antlr.v4.runtime.ParserRuleContext;
import org.antlr.v4.runtime.Token;

import java.util.List;

/**
 * Created by Ben on 05/12/2015.
 */
public abstract class FunctionVisitor<Program> extends NebBaseVisitor<ICode> {
    private final ProgramFactory<Program> factory = getFactory();
    private VariableTable table;

    protected abstract ProgramFactory<Program> getFactory();

    public FunctionVisitor(VariableTable table) {
        this.table = table;
    }

    @Override
    protected ICode defaultResult() {
        return factory.defaultCode();
    }

    @Override
    protected ICode aggregateResult(ICode aggregate, ICode nextResult) {
        return factory.aggregateCode(aggregate, nextResult);
    }

    @Override
    public ICode visitAddExpr(NebParser.AddExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitBinaryExpr(ctx.ops, ctx.args);
    }

    @Override
    public ICode visitMulExpr(NebParser.MulExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitBinaryExpr(ctx.ops, ctx.args);
    }

    @Override
    public ICode visitTernExpr(NebParser.TernExprContext ctx) {
        if(ctx.args.size() == 0) {
            return visit(ctx.single);
        }

        return visitTernExpr(ctx.args, 0);
    }

    private ICode visitTernExpr(List<? extends ParserRuleContext> args, int i) {
        if(i == args.size() - 1) {
            return visit(args.get(i));
        }

        return factory.ternaryExpression(visit(args.get(i)), visit(args.get(i + 1)), visitTernExpr(args, i + 2));
    }

    @Override
    public ICode visitLorExpr(NebParser.LorExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitBinaryExpr(ctx.ops, ctx.args);
    }

    @Override
    public ICode visitLandExpr(NebParser.LandExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitBinaryExpr(ctx.ops, ctx.args);
    }

    @Override
    public ICode visitEqualityExpr(NebParser.EqualityExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitBinaryExpr(ctx.ops, ctx.args);
    }

    @Override
    public ICode visitRelExpr(NebParser.RelExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitBinaryExpr(ctx.ops, ctx.args);
    }

    @Override
    public ICode visitPowExpr(NebParser.PowExprContext ctx) {
        if(ctx.args.size() == 0) {
            return visit(ctx.single);
        }

        return visitPowExpr(ctx.args, 0);
    }

    private ICode visitPowExpr(List<? extends ParserRuleContext> args, int i) {
        if(i == args.size() - 1) {
            return visit(args.get(i));
        }

        return factory.powerExpression(visit(args.get(i)), visitPowExpr(args, i + 1));
    }

    @Override
    public ICode visitUnaryExpr(NebParser.UnaryExprContext ctx) {
        if(ctx.ops.size() == 0) {
            return visit(ctx.single);
        }

        return visitUnaryExpr(ctx.ops, visit(ctx.arg));
    }


    @Override
    public ICode visitVariableReference(NebParser.VariableReferenceContext ctx) {
        String text = ctx.getText();

        if(table.isParameter(text)) {
            return factory.referenceParameter(text);
        }

        return factory.referenceOther(text);
    }

    @Override
    public ICode visitParenExpr(NebParser.ParenExprContext ctx) {
        return factory.parenExpression(visit(ctx.expr()));
    }

    @Override
    public ICode visitNumberExpr(NebParser.NumberExprContext ctx) {
        return factory.referenceOther(ctx.getText());
    }

    @Override
    public ICode visitIndexedVariable(NebParser.IndexedVariableContext ctx) {
        String name = ctx.name.getText();

        if(table.isRandomSource(name)) {
            return factory.referenceRandomSource(name);
        }

        if(table.isState(name)) {
            return factory.referenceState(name);
        }

        if(Type.isArray(table.getType(name))) {
            return factory.referenceArray(name);
        }

        return factory.referenceOther(name);
    }

    private ICode visitBinaryExpr(List<Token> ops, List<? extends ParserRuleContext> args) {
        return visitBinaryExpr(ops, args, 0);
    }

    private ICode visitBinaryExpr(List<Token> ops, List<? extends ParserRuleContext> args, int i) {
        ICode current = visit(args.get(i));

        if (i == ops.size()) {
            return current;
        }

        ICode operator = factory.operator(ops.get(i));

        ICode next = visitBinaryExpr(ops, args, i + 1);

        ICode result = factory.binaryExpression(current, operator, next);

        return result;
    }

    private ICode visitUnaryExpr(List<Token> ops, ICode arg) {
        return visitUnaryExpr(ops, arg, 0);
    }

    private ICode visitUnaryExpr(List<Token> ops, ICode arg, int i) {
        if (i == ops.size()) {
            return arg;
        }

        ICode operator = factory.operator(ops.get(i));

        ICode next = visitUnaryExpr(ops, arg, i + 1);

        ICode result = factory.unaryExpression(operator, next);

        return result;
    }

    @Override
    public ICode visitMathUnaryExpr(NebParser.MathUnaryExprContext ctx) {
        return factory.mathUnaryFunction(factory.mathFunction(ctx.function.getText()), visit(ctx.arg));

    }

    @Override
    public ICode visitMathBinaryExpr(NebParser.MathBinaryExprContext ctx) {
        return factory.mathBinaryFunction(factory.mathFunction(ctx.function.getText()), visit(ctx.arg1), visit(ctx.arg2));

    }
}
