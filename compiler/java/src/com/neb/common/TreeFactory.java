package com.neb.common;

import com.neb.Main;
import com.neb.common.codes.*;
import org.antlr.v4.runtime.Token;

import java.util.Arrays;
import java.util.List;

/**
 * Created by Ben on 21/11/2015.
 */
public abstract class TreeFactory<Program extends TreeProgram> implements ProgramFactory<Program> {
    @Override
    public Program stateInitialisation(String name, String value, Type type) {
        return (Program) defaultProgram().addStateVariable(new StringVariable(type, name, value));
    }

    @Override
    public Program modelParameter(String name, String value, Type type) {
        return (Program) defaultProgram().addConstant(new StringVariable(type, name, value));
    }

    @Override
    public Program modelArrayParameter(String name, List<String> elements, Type type) {
        String value = "{" + String.join(", ", elements) + "}";

        return (Program) defaultProgram().addConstant(new StringVariable(type, name, value, elements.size()));
    }

    @Override
    public Program randomSource(String name, Type inputType, RandomSet set, String from, String to) {
        return (Program) defaultProgram().addRandomSource(new StringRandomSource(name, set, from, to));
    }

    @Override
    public Program updateFunction(String name, ICode update) {
        return (Program) defaultProgram().addUpdateFunction(name, update);
    }

    @Override
    public Program payoffFunction(ICode payoff) {
        return (Program) defaultProgram().setPayoff(payoff);
    }

    @Override
    public Program outputFunction(String variable) {
        return (Program) defaultProgram().setOutputValue(variable);
    }

    @Override
    public ICode referenceRandomSource(String name) {
        return codeFromString(String.format("%s[id]", name));
    }

    @Override
    public ICode referenceArray(String name) {
        return new ArrayReferenceCode(name + (Main.OPTIMISE_SUB_EXPRESSIONS ? "Now" : "[i % 3]"));
    }

    @Override
    public ICode referenceParameter(String name) {
        return codeFromString(name);
    }

    @Override
    public ICode referenceOther(String name) {
        return codeFromString(name);
    }

    @Override
    public ICode binaryExpression(ICode current, ICode operator, ICode next) {
        return new BinaryExpressionCode(current, operator, next);
    }

    @Override
    public ICode unaryExpression(ICode operator, ICode next) {
        return codeFromCodes(operator, next);
    }

    @Override
    public ICode ternaryExpression(ICode condition, ICode ifThen, ICode elseThen) {
        return codeFromCodes(condition, codeFromString(" ? "), ifThen, codeFromString(" : "), elseThen);
    }

    @Override
    public ICode powerExpression(ICode x, ICode y) {
        return codeFromCodes(codeFromString("pow("), x, codeFromString(", "), y, codeFromString(")"));
    }

    @Override
    public ICode parenExpression(ICode inside) {
        return codeFromCodes(codeFromString("("), inside, codeFromString(")"));
    }

    @Override
    public ICode mathUnaryFunction(ICode operator, ICode value) {
        return new MathUnaryFunctionCode(operator, value);
    }

    @Override
    public ICode mathBinaryFunction(ICode operator, ICode a, ICode b) {
        return new MathBinaryFunctionCode(operator, a, b);
    }

    @Override
    public ICode referenceState(String name) {
        return codeFromString(name);
    }

    @Override
    public ICode mathFunction(String text) {
        return codeFromString(CUtils.mathFunction(text));
    }

    @Override
    public ICode operator(Token token) {
        return codeFromString(token.getText());
    }

    protected ICode codeFromTemplate(String template, ICode... ICode) {
        return codeFromString(String.format(template, ICode));
    }

    protected ICode codeFromCodes(ICode... ICodes) {
        return codeFromCodes(Arrays.asList(ICodes));
    }

    protected ICode codeFromString(String template) {
        return new TreeCode(template);
    }
    protected ICode codeFromCodes(List<ICode> ICodes) {
        return new TreeCode(ICodes);
    }

    @Override
    public ICode defaultCode() {
        return new TreeCode();
    }

    @Override
    public ICode aggregateCode(ICode aggregate, ICode next) {
        return new TreeCode(aggregate, next);
    }
}
