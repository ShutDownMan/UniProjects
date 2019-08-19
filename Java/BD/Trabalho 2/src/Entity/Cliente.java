package Entity;

public class Cliente {
    private int id;

    private String nome;

    private String cpf;

    private Endereco endereco;

    public Cliente(int id, String nome, String cpf, Endereco endereco) {
        this.id = id;
        this.nome = nome.trim();
        this.cpf = cpf.trim();
        this.endereco = endereco;
    }

    @Override
    public String toString() {
        return String.format("Cliente {\n\tid = %03d\n\tnome = '%s'\n\tcpf = '%s'\n\tendereco = '%s'\n}", id, nome, cpf, endereco.toString());
    }

    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public String getCpf() {
        return cpf;
    }

    public Endereco getEndereco() {
        return endereco;
    }
}
