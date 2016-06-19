package com.neb.common.codes;

import sun.reflect.generics.tree.Tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;

/**
 * Created by Ben on 05/12/2015.
 */
public class TreeCode extends StringCode {
    private List<ICode> children = new ArrayList<>();

    private ICode parent;
    private boolean replaced = false;

    public TreeCode(String code) {
        super(code);
    }

    public TreeCode() {}

    public TreeCode(ICode... codes) {
        Collections.addAll(children, codes);
        setParentOnChildren();
    }

    public TreeCode(List<ICode> codes) {
        children.addAll(codes);
        setParentOnChildren();
    }

    private void setParentOnChildren() {
        children.forEach(code -> code.setParent(this));
    }

    @Override
    public void setParent(ICode parent) {
        this.parent = parent;
    }

    @Override
    public void replace(ICode from, ICode with) {
        for(int i = 0; i < children.size(); i++) {
            if(from.equals(children.get(i))) {
                children.set(i, with);
            }
        }
    }

    @Override
    public void replace(ICode with) {
        parent.replace(this, with);
    }

    @Override
    public String reduce(Function<ICode, String> func) {
        String result = code;

        for (ICode child : children) {
            result += child.reduce(func);
        }

        return result;
    }

    @Override
    public void forEachWhere(Consumer<ICode> func, Function<ICode, Boolean> filter) {
        for (ICode child : children) {
            child.forEachWhere(func, filter);
        }

        if(filter.apply(this)) func.accept(this);
    }

    @Override
    public String toString() {
        return reduce(code -> code.toString());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;

        TreeCode treeCode = (TreeCode) o;

        if(treeCode.children.size() != children.size()) return false;

        for(int i = 0; i < children.size(); i++) {
            if (!treeCode.children.get(i).equals(children.get(i))) return false;
        }

        return true;
    }

    @Override
    public int hashCode() {
        return children.stream()
                .map(ICode::hashCode)
                .reduce(super.hashCode(), (a, b) -> a + b);
    }
}
