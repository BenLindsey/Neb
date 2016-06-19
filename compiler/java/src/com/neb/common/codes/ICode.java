package com.neb.common.codes;

import java.util.function.Consumer;
import java.util.function.Function;

/**
 * Created by bl2312 on 20/04/16.
 */
public interface ICode {
    default boolean isArrayReference() {
        return false;
    }

    default void forEachWhere(Consumer<ICode> func, Function<ICode, Boolean> filter) {
        if(filter.apply(this)) {
            func.accept(this);
        }
    }

    default String reduce(Function<ICode, String> func) {
        return func.apply(this);
    }

    default Boolean isUnaryFunction() {
        return false;
    }

    default Boolean isBinaryFunction() {
        return false;
    }

    default Boolean isBinaryExpression() {
        return false;
    }

    default void setParent(ICode parent) {

    }

    default void replace(ICode from, ICode with) {

    }

    default void replace(ICode with) {

    }
}
