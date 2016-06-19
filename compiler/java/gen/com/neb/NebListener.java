// Generated from /homes/bl2312/DSL/DSL/compiler/java/src/com/neb/Neb.g4 by ANTLR 4.5.1
package com.neb;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link NebParser}.
 */
public interface NebListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link NebParser#model}.
	 * @param ctx the parse tree
	 */
	void enterModel(NebParser.ModelContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#model}.
	 * @param ctx the parse tree
	 */
	void exitModel(NebParser.ModelContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#variableSection}.
	 * @param ctx the parse tree
	 */
	void enterVariableSection(NebParser.VariableSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#variableSection}.
	 * @param ctx the parse tree
	 */
	void exitVariableSection(NebParser.VariableSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#initialisationSection}.
	 * @param ctx the parse tree
	 */
	void enterInitialisationSection(NebParser.InitialisationSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#initialisationSection}.
	 * @param ctx the parse tree
	 */
	void exitInitialisationSection(NebParser.InitialisationSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#parameterSection}.
	 * @param ctx the parse tree
	 */
	void enterParameterSection(NebParser.ParameterSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#parameterSection}.
	 * @param ctx the parse tree
	 */
	void exitParameterSection(NebParser.ParameterSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#indexSection}.
	 * @param ctx the parse tree
	 */
	void enterIndexSection(NebParser.IndexSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#indexSection}.
	 * @param ctx the parse tree
	 */
	void exitIndexSection(NebParser.IndexSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#randomSection}.
	 * @param ctx the parse tree
	 */
	void enterRandomSection(NebParser.RandomSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#randomSection}.
	 * @param ctx the parse tree
	 */
	void exitRandomSection(NebParser.RandomSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#updateSection}.
	 * @param ctx the parse tree
	 */
	void enterUpdateSection(NebParser.UpdateSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#updateSection}.
	 * @param ctx the parse tree
	 */
	void exitUpdateSection(NebParser.UpdateSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#resultSection}.
	 * @param ctx the parse tree
	 */
	void enterResultSection(NebParser.ResultSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#resultSection}.
	 * @param ctx the parse tree
	 */
	void exitResultSection(NebParser.ResultSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#outputSection}.
	 * @param ctx the parse tree
	 */
	void enterOutputSection(NebParser.OutputSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#outputSection}.
	 * @param ctx the parse tree
	 */
	void exitOutputSection(NebParser.OutputSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#payoffSection}.
	 * @param ctx the parse tree
	 */
	void enterPayoffSection(NebParser.PayoffSectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#payoffSection}.
	 * @param ctx the parse tree
	 */
	void exitPayoffSection(NebParser.PayoffSectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclaration(NebParser.VariableDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclaration(NebParser.VariableDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#stateInitialisation}.
	 * @param ctx the parse tree
	 */
	void enterStateInitialisation(NebParser.StateInitialisationContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#stateInitialisation}.
	 * @param ctx the parse tree
	 */
	void exitStateInitialisation(NebParser.StateInitialisationContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#modelParameter}.
	 * @param ctx the parse tree
	 */
	void enterModelParameter(NebParser.ModelParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#modelParameter}.
	 * @param ctx the parse tree
	 */
	void exitModelParameter(NebParser.ModelParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#parameterValue}.
	 * @param ctx the parse tree
	 */
	void enterParameterValue(NebParser.ParameterValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#parameterValue}.
	 * @param ctx the parse tree
	 */
	void exitParameterValue(NebParser.ParameterValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#indexSource}.
	 * @param ctx the parse tree
	 */
	void enterIndexSource(NebParser.IndexSourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#indexSource}.
	 * @param ctx the parse tree
	 */
	void exitIndexSource(NebParser.IndexSourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#randomSource}.
	 * @param ctx the parse tree
	 */
	void enterRandomSource(NebParser.RandomSourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#randomSource}.
	 * @param ctx the parse tree
	 */
	void exitRandomSource(NebParser.RandomSourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#updateFunction}.
	 * @param ctx the parse tree
	 */
	void enterUpdateFunction(NebParser.UpdateFunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#updateFunction}.
	 * @param ctx the parse tree
	 */
	void exitUpdateFunction(NebParser.UpdateFunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#outputFunction}.
	 * @param ctx the parse tree
	 */
	void enterOutputFunction(NebParser.OutputFunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#outputFunction}.
	 * @param ctx the parse tree
	 */
	void exitOutputFunction(NebParser.OutputFunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#payoffFunction}.
	 * @param ctx the parse tree
	 */
	void enterPayoffFunction(NebParser.PayoffFunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#payoffFunction}.
	 * @param ctx the parse tree
	 */
	void exitPayoffFunction(NebParser.PayoffFunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#indexRange}.
	 * @param ctx the parse tree
	 */
	void enterIndexRange(NebParser.IndexRangeContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#indexRange}.
	 * @param ctx the parse tree
	 */
	void exitIndexRange(NebParser.IndexRangeContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#randomRange}.
	 * @param ctx the parse tree
	 */
	void enterRandomRange(NebParser.RandomRangeContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#randomRange}.
	 * @param ctx the parse tree
	 */
	void exitRandomRange(NebParser.RandomRangeContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(NebParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(NebParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#ternExpr}.
	 * @param ctx the parse tree
	 */
	void enterTernExpr(NebParser.TernExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#ternExpr}.
	 * @param ctx the parse tree
	 */
	void exitTernExpr(NebParser.TernExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#lorExpr}.
	 * @param ctx the parse tree
	 */
	void enterLorExpr(NebParser.LorExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#lorExpr}.
	 * @param ctx the parse tree
	 */
	void exitLorExpr(NebParser.LorExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#landExpr}.
	 * @param ctx the parse tree
	 */
	void enterLandExpr(NebParser.LandExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#landExpr}.
	 * @param ctx the parse tree
	 */
	void exitLandExpr(NebParser.LandExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#equalityExpr}.
	 * @param ctx the parse tree
	 */
	void enterEqualityExpr(NebParser.EqualityExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#equalityExpr}.
	 * @param ctx the parse tree
	 */
	void exitEqualityExpr(NebParser.EqualityExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#relExpr}.
	 * @param ctx the parse tree
	 */
	void enterRelExpr(NebParser.RelExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#relExpr}.
	 * @param ctx the parse tree
	 */
	void exitRelExpr(NebParser.RelExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#addExpr}.
	 * @param ctx the parse tree
	 */
	void enterAddExpr(NebParser.AddExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#addExpr}.
	 * @param ctx the parse tree
	 */
	void exitAddExpr(NebParser.AddExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#mulExpr}.
	 * @param ctx the parse tree
	 */
	void enterMulExpr(NebParser.MulExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#mulExpr}.
	 * @param ctx the parse tree
	 */
	void exitMulExpr(NebParser.MulExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#powExpr}.
	 * @param ctx the parse tree
	 */
	void enterPowExpr(NebParser.PowExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#powExpr}.
	 * @param ctx the parse tree
	 */
	void exitPowExpr(NebParser.PowExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#unaryExpr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryExpr(NebParser.UnaryExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#unaryExpr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryExpr(NebParser.UnaryExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#atomExpr}.
	 * @param ctx the parse tree
	 */
	void enterAtomExpr(NebParser.AtomExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#atomExpr}.
	 * @param ctx the parse tree
	 */
	void exitAtomExpr(NebParser.AtomExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#numberArray}.
	 * @param ctx the parse tree
	 */
	void enterNumberArray(NebParser.NumberArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#numberArray}.
	 * @param ctx the parse tree
	 */
	void exitNumberArray(NebParser.NumberArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#integerArray}.
	 * @param ctx the parse tree
	 */
	void enterIntegerArray(NebParser.IntegerArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#integerArray}.
	 * @param ctx the parse tree
	 */
	void exitIntegerArray(NebParser.IntegerArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#integerElement}.
	 * @param ctx the parse tree
	 */
	void enterIntegerElement(NebParser.IntegerElementContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#integerElement}.
	 * @param ctx the parse tree
	 */
	void exitIntegerElement(NebParser.IntegerElementContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#realArray}.
	 * @param ctx the parse tree
	 */
	void enterRealArray(NebParser.RealArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#realArray}.
	 * @param ctx the parse tree
	 */
	void exitRealArray(NebParser.RealArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#realElement}.
	 * @param ctx the parse tree
	 */
	void enterRealElement(NebParser.RealElementContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#realElement}.
	 * @param ctx the parse tree
	 */
	void exitRealElement(NebParser.RealElementContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#numberExpr}.
	 * @param ctx the parse tree
	 */
	void enterNumberExpr(NebParser.NumberExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#numberExpr}.
	 * @param ctx the parse tree
	 */
	void exitNumberExpr(NebParser.NumberExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#mathFuncExpr}.
	 * @param ctx the parse tree
	 */
	void enterMathFuncExpr(NebParser.MathFuncExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#mathFuncExpr}.
	 * @param ctx the parse tree
	 */
	void exitMathFuncExpr(NebParser.MathFuncExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#mathUnaryExpr}.
	 * @param ctx the parse tree
	 */
	void enterMathUnaryExpr(NebParser.MathUnaryExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#mathUnaryExpr}.
	 * @param ctx the parse tree
	 */
	void exitMathUnaryExpr(NebParser.MathUnaryExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#mathBinaryExpr}.
	 * @param ctx the parse tree
	 */
	void enterMathBinaryExpr(NebParser.MathBinaryExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#mathBinaryExpr}.
	 * @param ctx the parse tree
	 */
	void exitMathBinaryExpr(NebParser.MathBinaryExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#parenExpr}.
	 * @param ctx the parse tree
	 */
	void enterParenExpr(NebParser.ParenExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#parenExpr}.
	 * @param ctx the parse tree
	 */
	void exitParenExpr(NebParser.ParenExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#indexedVariable}.
	 * @param ctx the parse tree
	 */
	void enterIndexedVariable(NebParser.IndexedVariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#indexedVariable}.
	 * @param ctx the parse tree
	 */
	void exitIndexedVariable(NebParser.IndexedVariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#variableReference}.
	 * @param ctx the parse tree
	 */
	void enterVariableReference(NebParser.VariableReferenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#variableReference}.
	 * @param ctx the parse tree
	 */
	void exitVariableReference(NebParser.VariableReferenceContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#constantExpression}.
	 * @param ctx the parse tree
	 */
	void enterConstantExpression(NebParser.ConstantExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#constantExpression}.
	 * @param ctx the parse tree
	 */
	void exitConstantExpression(NebParser.ConstantExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#mathUnaryFunc}.
	 * @param ctx the parse tree
	 */
	void enterMathUnaryFunc(NebParser.MathUnaryFuncContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#mathUnaryFunc}.
	 * @param ctx the parse tree
	 */
	void exitMathUnaryFunc(NebParser.MathUnaryFuncContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#mathBinaryFunc}.
	 * @param ctx the parse tree
	 */
	void enterMathBinaryFunc(NebParser.MathBinaryFuncContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#mathBinaryFunc}.
	 * @param ctx the parse tree
	 */
	void exitMathBinaryFunc(NebParser.MathBinaryFuncContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#randomSet}.
	 * @param ctx the parse tree
	 */
	void enterRandomSet(NebParser.RandomSetContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#randomSet}.
	 * @param ctx the parse tree
	 */
	void exitRandomSet(NebParser.RandomSetContext ctx);
	/**
	 * Enter a parse tree produced by {@link NebParser#sensitivityFunction}.
	 * @param ctx the parse tree
	 */
	void enterSensitivityFunction(NebParser.SensitivityFunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link NebParser#sensitivityFunction}.
	 * @param ctx the parse tree
	 */
	void exitSensitivityFunction(NebParser.SensitivityFunctionContext ctx);
}