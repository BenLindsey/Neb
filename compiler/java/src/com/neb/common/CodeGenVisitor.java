package com.neb.common;

import com.neb.NebBaseVisitor;
import com.neb.NebParser;
import com.neb.common.codes.ICode;
import org.antlr.v4.runtime.RuleContext;

import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by Ben on 21/11/2015.
 */
public abstract class CodeGenVisitor<Program> extends NebBaseVisitor<Program> {
    private VariableTable table = new VariableTable();
    private ProgramFactory<Program> factory;

    public CodeGenVisitor() {
        factory = setFactory();
    }

    protected abstract ProgramFactory<Program> setFactory();

    protected abstract NebBaseVisitor<ICode> newUpdateVisitor(VariableTable table);

    protected abstract NebBaseVisitor<ICode> newPayoffVisitor(VariableTable table);

    @Override
    protected Program aggregateResult(Program aggregate, Program nextResult) {
        return factory.aggregateProgram(aggregate, nextResult);
    }

    @Override
    protected Program defaultResult() {
        return factory.defaultProgram();
    }

    @Override
    public Program visitIndexSource(NebParser.IndexSourceContext ctx) {
        return defaultResult();
    }

    @Override
    public Program visitRandomSource(NebParser.RandomSourceContext ctx) {
        String name = ctx.name.getText();

        RandomSet set = RandomSet.fromString(ctx.randomRange().set.getText());

        Type inputType = Type.fromRandomSet(set);

        table.addRandomSource(name, inputType);

        return factory.randomSource(
                name,
                inputType,
                set,
                ctx.randomRange().from.getText(),
                ctx.randomRange().to.getText()
        );
    }

    @Override
    public Program visitUpdateFunction(NebParser.UpdateFunctionContext ctx) {
        table.setOutputType(new TypeVisitor(table).visit(ctx.expr()));

        return factory.updateFunction(
                ctx.indexedVariable().name.getText(),
                newUpdateVisitor(table).visit(ctx.expr())
        );
    }

    @Override
    public Program visitStateInitialisation(NebParser.StateInitialisationContext ctx) {
        String name = ctx.indexedState.name.getText();

        Type type = Type.getFromNumberExpr(ctx.value);

        table.addState(name, type);

        return factory.stateInitialisation(name, ctx.value.getText(), type);
    }

    @Override
    public Program visitModelParameter(NebParser.ModelParameterContext ctx) {
        String name = ctx.parameter.getText();

        Type type = ctx.value.numberExpr() != null ?
                Type.getFromNumberExpr(ctx.value.numberExpr()) :
                Type.getFromNumberArray(ctx.value.numberArray());

        table.addParameter(name, type);

        if(Type.isArray(type)) {
            List<String> elements = (ctx.value.numberArray().integerArray() != null ?
                    ctx.value.numberArray().integerArray().vals :
                    ctx.value.numberArray().realArray().vals)
                    .stream()
                    .map(RuleContext::getText)
                    .collect(Collectors.toList());

            return factory.modelArrayParameter(name, elements, type);
        } else {
            return factory.modelParameter(name, ctx.value.getText(), type);
        }
    }

    @Override
    public Program visitOutputFunction(NebParser.OutputFunctionContext ctx) {
        return factory.outputFunction(ctx.indexedVariable().name.getText());
    }

    @Override
    public Program visitPayoffFunction(NebParser.PayoffFunctionContext ctx) {
        return factory.payoffFunction(
                newPayoffVisitor(table).visit(ctx.expr())
        );
    }
}
