package com.neb.common.codes;

import java.util.List;

public class StateVariableCode extends TreeCode {

    public StateVariableCode(String code) {
        super(code);
    }

    public StateVariableCode() {
        super();
    }

    public StateVariableCode(StateVariableCode... codes) {
        super(codes);
    }

    public StateVariableCode(List<StateVariableCode> codes) {
        super(codes.toArray(new StateVariableCode[codes.size()]));
    }

    public String asFine() {
        return reduce(code -> (code instanceof StateVariableCode) ?
                code.toString() + "_xf" : code.toString());
    }

    public String asCoarse() {
        return reduce(code -> (code instanceof StateVariableCode) ?
                code.toString() + "_xc" : code.toString());
    }
}
