package com.neb.maxeler;

import com.neb.common.TreeFactory;
import com.neb.common.codes.ICode;

import java.util.List;

/**
 * Created by benlindsey on 09/02/2016.
 */
public class MaxelerFactory extends TreeFactory<MaxelerProgram> {
    @Override
    public MaxelerProgram aggregateProgram(MaxelerProgram aggregate, MaxelerProgram nextResult) {
        return aggregate.merge(nextResult);
    }

    @Override
    public MaxelerProgram defaultProgram() {
        return new MaxelerProgram();
    }

    @Override
    public ICode referenceRandomSource(String name) {
        return codeFromString(name);
    }

    @Override
    public ICode referenceArray(String name) {
        return codeFromString(String.format("%s.read(yWrap)", name));
    } //todo wrap

    @Override
    public ICode mathFunction(String text) {
        return codeFromString(kernelFunction(text));
    }

    private String kernelFunction(String text) {
        return "Kernel" + javaFunction(text);
    }

    private String javaFunction(String text) {
        switch (text) {
            case "\\exp":
                return "Math.exp";
            case "\\sqrt":
                return "Math.sqrt";
            case "\\max":
                return "Math.max";
            default:
                throw new RuntimeException("Unknown math function");
        }
    }
}
