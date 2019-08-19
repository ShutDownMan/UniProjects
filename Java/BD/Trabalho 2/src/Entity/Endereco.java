package Entity;

public class Endereco {
    private int id;

    private String pais;

    private String estado;

    private String cidade;

    private String logradouro;

    private String rua;

    private int numero;

    public Endereco(int id, String rua, String logradouro, String cidade, int numero) {
        this.id = id;
        this.cidade = cidade.trim();
        this.logradouro = logradouro.trim();
        this.rua = rua.trim();
        this.numero = numero;
    }

    public Endereco(int id, String rua, String logradouro, String cidade, String estado, String pais, int numero) {
        this.id = id;
        this.pais = pais.trim();
        this.estado = estado.trim();
        this.cidade = cidade.trim();
        this.logradouro = logradouro.trim();
        this.rua = rua.trim();
        this.numero = numero;
    }

    @Override
    public String toString() {
        if(this.estado == null)
            return String.format("Cidade %s, %s %s, Numero %03d", this.cidade, this.logradouro, this.rua, this.numero);
        return String.format("Pais %s, Estado %s, Cidade %s, %s %s, Numero %03d", this.pais, this.estado, this.cidade, this.logradouro, this.rua, this.numero);
    }

    public int getId() {
        return id;
    }

    public String getPais() {
        return pais;
    }

    public String getEstado() {
        return estado;
    }

    public String getCidade() {
        return cidade;
    }

    public String getLogradouro() {
        return logradouro;
    }

    public String getRua() {
        return rua;
    }

    public int getNumero() {
        return numero;
    }
}
