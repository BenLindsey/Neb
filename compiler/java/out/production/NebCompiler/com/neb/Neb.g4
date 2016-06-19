grammar Neb;

model: variableSection initialisationSection parameterSection indexSection randomSection updateSection resultSection;

variableSection: '% State Variables' declarations+=variableDeclaration*;

initialisationSection: '% State Initialisation' initialisations+=stateInitialisation*;

parameterSection: '% Model Parameters' parameters+=modelParameter*;

indexSection: '% State Index' indexes+=indexSource*;

randomSection: '% Random Source' randomSources+=randomSource*;

updateSection: '% State Update' updateFunctions+=updateFunction*;

resultSection: outputSection | payoffSection;

outputSection: '% Output' outputFunctions+=outputFunction*;

payoffSection: '% Payoff' payoffFunction;

variableDeclaration: name=ID;

stateInitialisation: indexedState=indexedVariable '=' value=numberExpr;

modelParameter: parameter=ID '=' value=parameterValue;

parameterValue: numberExpr | numberArray;

indexSource: name=ID '\\in' source=indexRange;

randomSource: name=ID '\\sim' randomRange;

updateFunction: indexedVariable '=' expr;

outputFunction: indexedVariable;

payoffFunction: expr;

indexRange: '[' from=constantExpression '..' to=constantExpression ']';

randomRange: set=randomSet '[' from=constantExpression ',' to=constantExpression ']';

expr: ternExpr;

ternExpr: single=lorExpr | args+=lorExpr ('?' args+=lorExpr ':' args+=lorExpr)+;

lorExpr: single=landExpr | args+=landExpr (ops+='||' args+=landExpr)+;

landExpr: single=equalityExpr | args+=equalityExpr (ops+='&&' args+=equalityExpr)+;

equalityExpr: single=relExpr | args+=relExpr ((ops+='==' | ops+='!=') args+=relExpr)+;

relExpr: single=addExpr | args+=addExpr ((ops+='<' | ops+='<=' | ops+='>' | ops+='>=') args+=addExpr)+;

addExpr: single=mulExpr | args+=mulExpr ((ops+='+' | ops+='-') args+=mulExpr)+;

mulExpr: single=powExpr | args+=powExpr ((ops+='*' | ops+='/') args+=powExpr)+;

powExpr: single=unaryExpr | args+=unaryExpr ('^' args+=unaryExpr)+;

unaryExpr: single=atomExpr | (ops+='+' | ops+='-' | ops+='!')+ arg=atomExpr;

atomExpr: indexedVariable | variableReference | numberExpr | mathFuncExpr | parenExpr;

numberArray: integerArray | realArray;

integerArray: '[' vals+=integerElement (',' vals+=integerElement)* ']';

integerElement: INTEGER | '-' INTEGER;

realArray: '[' vals+=realElement (',' vals+=realElement)* ']';

realElement: REAL | '-' REAL;

numberExpr: integer=INTEGER | real=realElement;

mathFuncExpr: mathUnaryExpr | mathBinaryExpr ;

mathUnaryExpr: function=mathUnaryFunc '{' arg=expr '}';

mathBinaryExpr: function=mathBinaryFunc '{' arg1=expr '}' '{' arg2=expr '}';

parenExpr: '(' arg=expr ')';

indexedVariable: name=ID '_{' index=constantExpression '}';

variableReference: name=ID;

constantExpression: expr;

mathUnaryFunc: '\\sqrt' | '\\exp';

mathBinaryFunc: '\\max';

randomSet: 'Z' | 'R' | 'N';

ID: ('a'..'z' | 'A'..'Z') (DIGIT | 'a'..'z' | 'A'..'Z')*;

REAL: INTEGER '.' INTEGER | INTEGER '.' INTEGER 'f';

INTEGER: (DIGIT)+;

fragment DIGIT  : '0'..'9';

WS: [\t\r\n\u000C ]+ -> skip;