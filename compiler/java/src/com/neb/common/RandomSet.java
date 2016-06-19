package com.neb.common;

/**
 * Created by benlindsey on 06/01/2016.
 */
public enum RandomSet {
    N, Z, R;

    public static RandomSet fromString(String set) {
        switch(set.toUpperCase()) {
            case "R":
                return RandomSet.R;
            case "N":
                return RandomSet.N;
            case "Z":
                return RandomSet.Z;
            default:
                throw new RuntimeException("Invalid random set");
        }
    }
}
