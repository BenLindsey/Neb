package com.neb.common;

import com.neb.common.Type;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by Ben on 05/12/2015.
 */
public class VariableTable {
    private Map<String, Type> randomTypes = new HashMap<>();
    private Map<String, Type> stateTypes = new HashMap<>();
    private Map<String, Type> paramTypes = new HashMap<>();
    private Type outputType = Type.INT;

    public void addRandomSource(String name, Type type) {
        randomTypes.put(name, type);
    }

    public void addState(String name, Type type) {
        stateTypes.put(name, type);
    }

    public void addParameter(String name, Type type) {
        paramTypes.put(name, type);
    }

    public Type getType(String name) {
        if(isState(name)) {
            return stateTypes.get(name);
        }

        if(isRandomSource(name)) {
            return randomTypes.get(name);
        }

        if(isParameter(name)) {
            return paramTypes.get(name);
        }

        return Type.INT;
    }

    public boolean isRandomSource(String name) {
        return randomTypes.containsKey(name);
    }

    public boolean isState(String name) {
        return stateTypes.containsKey(name);
    }

    public boolean isParameter(String name) {
        return paramTypes.containsKey(name);
    }

    public void setOutputType(Type type) {
        outputType = type;
    }

    public Type getOutputType() {
        return outputType;
    }
}
