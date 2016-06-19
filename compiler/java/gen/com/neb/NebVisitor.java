// Generated from /homes/bl2312/DSL/DSL/compiler/java/src/com/neb/Neb.g4 by ANTLR 4.5.1
package com.neb;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link NebParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface NebVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link NebParser#model}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModel(NebParser.ModelContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#variableSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableSection(NebParser.VariableSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#initialisationSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitialisationSection(NebParser.InitialisationSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#parameterSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterSection(NebParser.ParameterSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#indexSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIndexSection(NebParser.IndexSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#randomSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRandomSection(NebParser.RandomSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#updateSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdateSection(NebParser.UpdateSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#resultSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitResultSection(NebParser.ResultSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#outputSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOutputSection(NebParser.OutputSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#payoffSection}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPayoffSection(NebParser.PayoffSectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#variableDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableDeclaration(NebParser.VariableDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#stateInitialisation}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStateInitialisation(NebParser.StateInitialisationContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#modelParameter}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModelParameter(NebParser.ModelParameterContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#parameterValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterValue(NebParser.ParameterValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#indexSource}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIndexSource(NebParser.IndexSourceContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#randomSource}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRandomSource(NebParser.RandomSourceContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#updateFunction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdateFunction(NebParser.UpdateFunctionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#outputFunction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOutputFunction(NebParser.OutputFunctionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#payoffFunction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPayoffFunction(NebParser.PayoffFunctionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#indexRange}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIndexRange(NebParser.IndexRangeContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#randomRange}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRandomRange(NebParser.RandomRangeContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(NebParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#ternExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTernExpr(NebParser.TernExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#lorExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLorExpr(NebParser.LorExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#landExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLandExpr(NebParser.LandExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#equalityExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEqualityExpr(NebParser.EqualityExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#relExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRelExpr(NebParser.RelExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#addExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddExpr(NebParser.AddExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#mulExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMulExpr(NebParser.MulExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#powExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPowExpr(NebParser.PowExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#unaryExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnaryExpr(NebParser.UnaryExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#atomExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtomExpr(NebParser.AtomExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#numberArray}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumberArray(NebParser.NumberArrayContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#integerArray}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntegerArray(NebParser.IntegerArrayContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#integerElement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntegerElement(NebParser.IntegerElementContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#realArray}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRealArray(NebParser.RealArrayContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#realElement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRealElement(NebParser.RealElementContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#numberExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumberExpr(NebParser.NumberExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#mathFuncExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMathFuncExpr(NebParser.MathFuncExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#mathUnaryExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMathUnaryExpr(NebParser.MathUnaryExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#mathBinaryExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMathBinaryExpr(NebParser.MathBinaryExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#parenExpr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParenExpr(NebParser.ParenExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#indexedVariable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIndexedVariable(NebParser.IndexedVariableContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#variableReference}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableReference(NebParser.VariableReferenceContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#constantExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantExpression(NebParser.ConstantExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#mathUnaryFunc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMathUnaryFunc(NebParser.MathUnaryFuncContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#mathBinaryFunc}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMathBinaryFunc(NebParser.MathBinaryFuncContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#randomSet}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRandomSet(NebParser.RandomSetContext ctx);
	/**
	 * Visit a parse tree produced by {@link NebParser#sensitivityFunction}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSensitivityFunction(NebParser.SensitivityFunctionContext ctx);
}