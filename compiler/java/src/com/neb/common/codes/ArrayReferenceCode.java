package com.neb.common.codes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;

/**
 * Created by Ben on 05/12/2015.
 */
public class ArrayReferenceCode extends TreeCode {
    public ArrayReferenceCode(String code) {
        super(code);
    }

    @Override
    public boolean isArrayReference() {
        return true;
    }
}
