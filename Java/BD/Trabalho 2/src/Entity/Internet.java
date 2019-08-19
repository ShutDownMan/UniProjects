package Entity;

public class Internet {
    private int id;

    private String data;

    private int volume;

    private double valor;

    private int id_fatura;

    public Internet(int id, String data, int volume, double valor, int id_fatura) {
        this.id = id;
        this.data = data;
        this.volume = volume;
        this.valor = valor;
        this.id_fatura = id_fatura;
    }

    @Override
    public String toString() {
        return String.format("Internet {\n\tid = %d\n\tdata = '%s'\n\tvolume = %d kbs\n\tvalor = R$ %.02f\n\tid_fatura = %d\n}", id, data, volume, valor, id_fatura);
    }

    public int getId() {
        return id;
    }

    public String getData() {
        return data;
    }

    public int getVolume() {
        return volume;
    }

    public double getValor() {
        return valor;
    }

    public int getId_fatura() {
        return id_fatura;
    }
}
