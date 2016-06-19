package com.neb.common;

import com.neb.NebParser;

/**
 * Created by Ben on 05/12/2015.
 */
public enum Type {
    INT, REAL, INT_ARRAY, REAL_ARRAY;

    public static Type fromRandomSet(RandomSet set) {
        switch(set) {
            case R:
            case N:
                return REAL;
            case Z:
                return INT;
            default:
                throw new RuntimeException("Unknown random set");
        }
    }


    public static Type getFromNumberExpr(NebParser.NumberExprContext ctx) {
        return ctx.integer != null ? Type.INT : Type.REAL;
    }

    public static Type getFromNumberArray(NebParser.NumberArrayContext ctx) {
        return ctx.integerArray() != null ? Type.INT_ARRAY : Type.REAL_ARRAY;
    }

    public static boolean isArray(Type type) {
        switch (type) {
            case INT:
            case REAL:
                return false;
            case INT_ARRAY:
            case REAL_ARRAY:
                return true;
            default:
                throw new RuntimeException("Unknown type, unsure if array or not");
        }
    }
}
