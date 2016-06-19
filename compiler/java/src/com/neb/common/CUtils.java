package com.neb.common;

/**
 * Created by Ben on 23/01/2016.
 */
public class CUtils {
    public static String mathFunction(String text) {
        switch (text) {
            case "\\exp":
                return "exp";
            case "\\sqrt":
                return "sqrt";
            case "\\max":
                return "max";
            default:
                throw new RuntimeException("Unknown math function");
        }
    }

    public static String floatFunction(String text) {
        switch (text) {
            case "\\max":
                return "fmax";
            default:
                return mathFunction(text);
        }
    }
}
