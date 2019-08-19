package Entity;

public class Fatura {
    private int id;

    private String cod_barra;

    private String vencimento;

    private String emissao;

    private int id_empresa_telecomunicacao;

    public Fatura(int id, String cod_barra, String vencimento, String emissao, int id_empresa_telecomunicacao) {
        this.id = id;
        this.cod_barra = cod_barra;
        this.vencimento = vencimento;
        this.emissao = emissao;
        this.id_empresa_telecomunicacao = id_empresa_telecomunicacao;
    }

    @Override
    public String toString() {
        return "Fatura {" +
                "\n\tid = " + id +
                "\n\tcod_barra = '" + cod_barra + "'" +
                "\n\tvencimento = '" + vencimento + "'" +
                "\n\temissao = '" + emissao + "'" +
                "\n\tid_empresa_telecomunicacao = " + id_empresa_telecomunicacao +
                "\n}";
    }

    public int getId() {
        return id;
    }

    public String getCod_barra() {
        return cod_barra;
    }

    public String getVencimento() {
        return vencimento;
    }

    public String getEmissao() {
        return emissao;
    }

    public int getId_empresa_telecomunicacao() {
        return id_empresa_telecomunicacao;
    }
}
