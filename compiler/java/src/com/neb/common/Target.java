package com.neb.common;

public enum Target {
    OpenCL, CPP, Maxeler, CPPML, AD;

    public static Target fromString(String target) {
        switch (target.toLowerCase()) {
            case "opencl":
                return OpenCL;
            case "cpp":
                return CPP;
            case "maxeler":
                return Maxeler;
            case "cppml":
                return CPPML;
            case "ad":
                return AD;
            default:
                throw new RuntimeException("Invalid target");
        }
    }
}
