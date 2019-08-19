package Entity;

public class Ligacao {
    private int id;

    private String hora;

    private double valor;

    private int id_fatura;

    private String duracao;

    private String telefone;

    private String tipo;

    public Ligacao(int id, String hora, double valor, int id_fatura, String duracao, String telefone, String tipo) {
        this.id = id;
        this.hora = hora;
        this.valor = valor;
        this.id_fatura = id_fatura;
        this.duracao = duracao;
        this.telefone = telefone;
        this.tipo = tipo;
    }

    @Override
    public String toString() {
        return String.format("Ligacao {\n\tid = %d\n\thora = '%s'\n\tvalor = R$ %.02f\n\tid_fatura = %d\n\tduracao = '%s'\n\ttelefone = '%s'\n\ttipo = '%s'\n}", id, hora, valor, id_fatura, duracao, telefone, tipo);
    }

    public int getId() {
        return id;
    }

    public String getHora() {
        return hora;
    }

    public double getValor() {
        return valor;
    }

    public int getId_fatura() {
        return id_fatura;
    }

    public String getDuracao() {
        return duracao;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getTipo() {
        return tipo;
    }
}
