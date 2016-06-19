package com.neb.common.codes;

/**
 * Created by Ben on 05/12/2015.
 */
public class StringCode implements ICode {
    protected String code = "";

    public StringCode(String code) {
        this.code = code;
    }

    public StringCode() {
    }

    public StringCode(StringCode... codes) {
        for(StringCode nextCode : codes) {
            this.code += nextCode.code;
        }
    }

    public StringCode indent(int i) {
        StringCode code = this;

        for(int j = 0; j < i; j++) {
            code = code.indent();
        }

        return code;
    }

    public StringCode indent() {
        return new StringCode("  " + code);
    }

    @Override
    public String toString() {
        return code;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        StringCode that = (StringCode) o;

        return code != null ? code.equals(that.code) : that.code == null;

    }

    @Override
    public int hashCode() {
        return code != null ? code.hashCode() : 0;
    }

    public boolean isArrayReference() {
        return false;
    }
}
