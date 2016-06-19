package com.neb.common;

import com.neb.common.RandomSet;
import com.neb.common.Type;
import com.neb.common.codes.ICode;
import org.antlr.v4.runtime.Token;

import java.util.List;

/**
 * Created by Ben on 21/11/2015.
 */
public interface ProgramFactory<Program> {
    Program aggregateProgram(Program aggregate, Program nextResult);

    Program defaultProgram();

    Program stateInitialisation(String name, String value, Type type);

    Program modelParameter(String name, String value, Type type);

    Program modelArrayParameter(String name, List<String> elements, Type type);

    Program randomSource(String name, Type inputType, RandomSet set, String from, String to);

    Program outputFunction(String output);

    Program updateFunction(String name, ICode update);

    Program payoffFunction(ICode payoff);

    ICode defaultCode();

    ICode aggregateCode(ICode aggregate, ICode nextResult);

    ICode operator(Token token);

    ICode referenceRandomSource(String name);

    ICode referenceState(String name);

    ICode referenceParameter(String name);

    ICode mathFunction(String text);

    ICode referenceArray(String name);

    ICode referenceOther(String name);

    ICode binaryExpression(ICode current, ICode operator, ICode next);

    ICode unaryExpression(ICode operator, ICode next);

    ICode ternaryExpression(ICode condition, ICode ifThen, ICode elseThen);

    ICode powerExpression(ICode x, ICode y);

    ICode parenExpression(ICode inside);

    ICode mathUnaryFunction(ICode operator, ICode value);

    ICode mathBinaryFunction(ICode operator, ICode a, ICode b);
}
