public class Param {
    private String nome;
    private Enum<Tipo> tipo;
    private Object valor;

    Param(String nome, Enum<Tipo> tipo, Object valor) {
        this.nome = nome;
        this.tipo = tipo;
        this.valor = valor;
    }

    public String toString() {
        return this.nome + " = " + this.valor;
    }
}
