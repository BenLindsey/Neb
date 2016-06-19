package com.neb.common;

/**
 * Created by benlindsey on 07/01/2016.
 */
public class StringVariable {
    public Type type;
    public String name;
    public String initialValue;
    public int elements = 0;

    public StringVariable(Type type, String name) {
        this.type = type;
        this.name = name;
    }

    public StringVariable(Type type, String name, String initialValue) {
        this.type = type;
        this.name = name;
        this.initialValue = initialValue;
    }

    public StringVariable(Type type, String name, String initialValue, int elements) {
        this.type = type;
        this.name = name;
        this.initialValue = initialValue;
        this.elements = elements;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        StringVariable that = (StringVariable) o;

        if (type != that.type) return false;
        if (!name.equals(that.name)) return false;
        return initialValue != null ? initialValue.equals(that.initialValue) : that.initialValue == null;

    }

    @Override
    public int hashCode() {
        int result = type.hashCode();
        result = 31 * result + name.hashCode();
        result = 31 * result + (initialValue != null ? initialValue.hashCode() : 0);
        return result;
    }
}
