import Entity.*;

import java.sql.*;
import java.util.ArrayList;
import java.util.Properties;

class DBConnection {

    private Connection connection;


    void initialize() throws SQLException {
        String url = "jdbc:postgresql://localhost:5432/empresa_telecom";
        Properties props = new Properties();
        props.setProperty("user", "postgres");
        props.setProperty("password", "NotSafePasswd321");

        connection = DriverManager.getConnection(url, props);
    }

    void populate() throws SQLException {
        Statement st;
//        ResultSet rs;

        st = this.connection.createStatement();

        st.execute("INSERT INTO rua(nome) VALUES " +
                "('Rio de Janeiro'), ('377'), ('Brasil')");

        st.execute("INSERT INTO logradouro(nome) VALUES " +
                "('rua'), ('avenida'), ('rodovia')");

        st.execute("INSERT INTO pais(nome) VALUES " +
                "('Brasil')");

        st.execute("INSERT INTO estado(nome, id_pais) VALUES " +
                "('Parana', 1)");

        st.execute("INSERT INTO cidade(nome, id_estado) VALUES " +
                "('foz do iguacu', 1), ('curitiba', 1)");

        st.execute("INSERT INTO endereco(id_rua, id_logradouro, id_cidade, numero) VALUES " +
                "(1, 1, 1, 44), (2, 3, 2, 1456), (3, 2, 1, 445)");

        st.execute("INSERT INTO empresa_telecomunicacao(razao_social, cnpj, id_endereco) VALUES " +
                "('Click Internet', '12345678910119', 1)");

        st.execute("INSERT INTO cliente(nome, cpf, id_endereco) VALUES " +
                "('Guilherme Sganderla', '43423798645', 2)," +
                "('Vivian Fugihara', '46716678352', 3)");

        st.execute("INSERT INTO fatura(cod_barra, vencimento, emissao, id_empresa_telecomunicacao) VALUES " +
                "('1312151245495486', DATE '2019-09-30', DATE '2019-09-13', 1), " +
                "('5166516516516651', DATE '2019-08-29', DATE '2019-09-13', 1)");

        st.execute("INSERT INTO cliente_fatura(id_cliente, id_fatura) VALUES " +
                "(1, 2)," +
                "(2, 1)");

        st.execute("INSERT INTO ligacao(id_fatura, valor, hora, duracao, telefone, tipo) VALUES " +
                "(2, 1.27, TIMESTAMP WITH TIME ZONE '2019-08-15 13:15:54-03', INTERVAL '0 hours 07 mins 12 secs', '+55 45 9945-1231', 'local')," +
                "(2, 3.50, TIMESTAMP WITH TIME ZONE '2019-08-16 21:51:21-03', INTERVAL '0 hours 21 mins 51 secs', '+45 15 1651-515', 'internacional')," +
                "(2, 2.44, TIMESTAMP WITH TIME ZONE '2019-08-16 06:23:12-03', INTERVAL '0 hours 16 mins 31 secs', '+55 45 9906-3072', 'local')," +
                "(2, 3.57, TIMESTAMP WITH TIME ZONE '2019-08-16 02:16:11-03', INTERVAL '0 hours 28 mins 51 secs', '+55 41 9842-0677', 'interurbano')," +
                "(2, 5.32, TIMESTAMP WITH TIME ZONE '2019-08-16 15:46:12-03', INTERVAL '0 hours 41 mins 01 secs', '+55 45 9855-11191', 'local')");
        st.execute("INSERT INTO ligacao(id_fatura, valor, hora, duracao, telefone, tipo) VALUES " +
                "(1, 3.19, TIMESTAMP WITH TIME ZONE '2019-09-15 22:23:54-03', INTERVAL '0 hours 32 mins 33 secs', '+55 45 9926-5773', 'local')," +
                "(1, 1.26, TIMESTAMP WITH TIME ZONE '2019-09-16 10:15:12-03', INTERVAL '0 hours 06 mins 02 secs', '+55 45 9842-0677', 'local')," +
                "(1, 2.11, TIMESTAMP WITH TIME ZONE '2019-09-16 12:16:11-03', INTERVAL '0 hours 19 mins 10 secs', '+55 41 9842-0677', 'interurbano')," +
                "(1, 2.08, TIMESTAMP WITH TIME ZONE '2019-09-16 12:16:11-03', INTERVAL '0 hours 19 mins 30 secs', '+55 41 84165-5447', 'interurbano')," +
                "(1, 3.59, TIMESTAMP WITH TIME ZONE '2019-09-16 16:46:21-03', INTERVAL '0 hours 21 mins 21 secs', '+45 15 1651-515', 'internacional')," +
                "(1, 4.34, TIMESTAMP WITH TIME ZONE '2019-09-16 21:53:12-03', INTERVAL '0 hours 53 mins 35 secs', '+55 45 9926-5773', 'local')");

        st.execute("INSERT INTO internet(id_fatura, data, volume, valor) VALUES" +
                "(1, TIMESTAMP WITH TIME ZONE '2019-09-15 16:26:45-03', 2640, 0.03)," +
                "(1, TIMESTAMP WITH TIME ZONE '2019-09-16 01:57:39-03', 51302, 0.68)," +
                "(1, TIMESTAMP WITH TIME ZONE '2019-09-16 18:46:30-03', 21584, 0.20)");

        st.execute("INSERT INTO internet(id_fatura, data, volume, valor) VALUES" +
                "(2, TIMESTAMP WITH TIME ZONE '2019-08-15 17:13:42-03', 561320, 10.15)," +
                "(2, TIMESTAMP WITH TIME ZONE '2019-08-16 14:52:28-03', 651350, 12.41)");

        st.close();
    }

    ArrayList<Cliente> searchClientByName(String buffer) throws SQLException {
        ArrayList<Cliente> clientes = new ArrayList<>();
        Statement st = this.connection.createStatement();
        ResultSet rs;

        rs = st.executeQuery("SELECT * FROM cliente WHERE nome LIKE '%" + buffer + "%'");

        while (rs.next()) {
            clientes.add(new Cliente(
                    rs.getInt("id"),
                    rs.getString("nome"),
                    rs.getString("cpf"),
                    this.getEnderecoById(rs.getInt("id_endereco"))));
        }

        st.close();
        rs.close();
        return clientes;
    }

    private Endereco getEnderecoById(int id) throws SQLException {
        Endereco foundEndereco = null;
        Statement st = this.connection.createStatement();
        ResultSet rs;

        rs = st.executeQuery("SELECT * FROM endereco WHERE id=" + id + "");
        rs.next();
        foundEndereco = new Endereco(
                rs.getInt("id"),
                getStringAttrTableId("rua", "nome", rs.getInt("id_rua")),
                getStringAttrTableId("logradouro", "nome", rs.getInt("id_logradouro")),
                getStringAttrTableId("cidade", "nome", rs.getInt("id_cidade")),
                rs.getInt("numero"));

        st.close();
        rs.close();
        return foundEndereco;
    }

    private String getStringAttrTableId(String table, String attr, int id) throws SQLException {
        Statement st = this.connection.createStatement();
        ResultSet rs = st.executeQuery("SELECT * FROM " + table + " WHERE id=" + id + "");

        rs.next();
        String res = rs.getString(attr);

        st.close();
        rs.close();
        return res;
    }

    Cliente getClientById(int id) throws SQLException {
        Cliente foundCliente = null;
        Statement st = this.connection.createStatement();
        ResultSet rs;

        rs = st.executeQuery("SELECT * FROM cliente WHERE id=" + id + "");
        rs.next();
        foundCliente = new Cliente(
                rs.getInt("id"),
                rs.getString("nome"),
                rs.getString("cpf"),
                this.getEnderecoById(rs.getInt("id_endereco")));

        st.close();
        rs.close();
        return foundCliente;
    }

    ArrayList<Fatura> getFaturasByClientId(int id) throws SQLException {
        ArrayList<Fatura> faturas = new ArrayList<>();
        Cliente foundCliente = this.getClientById(id);
        Statement st = this.connection.createStatement();
        ResultSet rs;

        if (foundCliente == null)
            return null;

        rs = st.executeQuery("SELECT * FROM fatura WHERE id=" + id + "");
        while (rs.next()) {
            faturas.add(new Fatura(
                    rs.getInt("id"),
                    rs.getString("cod_barra"),
                    rs.getString("vencimento"),
                    rs.getString("emissao"),
                    rs.getInt("id_empresa_telecomunicacao")));
        }

        st.close();
        rs.close();
        return faturas;
    }

    Fatura getFaturaById(int id) throws SQLException {
        Fatura foundFatura = null;
        Statement st = this.connection.createStatement();
        ResultSet rs;

        rs = st.executeQuery("SELECT * FROM fatura WHERE id=" + id + "");
        rs.next();

        foundFatura = new Fatura(
                rs.getInt("id"),
                rs.getString("cod_barra"),
                rs.getString("vencimento"),
                rs.getString("emissao"),
                rs.getInt("id_empresa_telecomunicacao"));

        st.close();
        rs.close();
        return foundFatura;
    }

    ArrayList<Ligacao> getLigacoesByFaturaId(int id) throws SQLException {
        ArrayList<Ligacao> faturas = new ArrayList<>();
        Fatura foundFatura = this.getFaturaById(id);
        Statement st = this.connection.createStatement();
        ResultSet rs;

        if (foundFatura == null)
            return null;

        rs = st.executeQuery("SELECT * FROM ligacao WHERE id_fatura=" + id + "");
        while (rs.next()) {
            faturas.add(new Ligacao(
                    rs.getInt("id"),
                    rs.getString("hora"),
                    rs.getFloat("valor"),
                    rs.getInt("id_fatura"),
                    rs.getString("duracao"),
                    rs.getString("telefone"),
                    rs.getString("tipo")));
        }

        st.close();
        rs.close();
        return faturas;
    }

    ArrayList<Internet> getInternetByFaturaId(int id) throws SQLException {
        ArrayList<Internet> internetList = new ArrayList<>();
        Fatura foundFatura = this.getFaturaById(id);
        Statement st = this.connection.createStatement();
        ResultSet rs;

        if (foundFatura == null)
            return null;

        rs = st.executeQuery("SELECT * FROM internet WHERE id_fatura=" + id + "");
        while (rs.next()) {
            internetList.add(new Internet(
                    rs.getInt("id"),
                    rs.getString("data"),
                    rs.getInt("volume"),
                    rs.getFloat("valor"),
                    rs.getInt("id_fatura")));
        }

        st.close();
        rs.close();
        return internetList;
    }

    void close() throws SQLException {
        this.connection.close();
    }
}
