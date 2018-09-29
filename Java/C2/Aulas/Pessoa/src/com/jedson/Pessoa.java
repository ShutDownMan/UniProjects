package com.jedson;

public class Pessoa {
    private String cpf;
    private String nome;
    private char sexo;


    Pessoa(String cpf, String nome, char sexo) {
        this.cpf = cpf;
        this.nome = nome;
        this.sexo = sexo;
    }

    public String toString() {
        return String.format("%s %s %c", this.cpf, this.nome, this.sexo);
    }
}
