package com.jedson;

class Transition {
    Character readSymbol;
    State stateTo;
    Character writeSymbol;
    Integer moveDirection;

    /**
     * inicializa campos da transição
     * @param readSymbol simbolo de leitura
     * @param stateTo estado de chegada
     * @param writeSymbol simbolo de escrita
     * @param moveDirection direção de movimento
     */
    Transition(Character readSymbol, State stateTo, Character writeSymbol, Integer moveDirection) {
        this.readSymbol = readSymbol;
        this.stateTo = stateTo;
        this.writeSymbol = writeSymbol;
        this.moveDirection = moveDirection;
    }
}
