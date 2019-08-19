import Entity.Cliente;
import Entity.Fatura;
import Entity.Internet;
import Entity.Ligacao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static Scanner scanner;
    private static DBConnection dbConnection;

    public static void main(String[] args) {
        int opcao;

        scanner = new Scanner(System.in);
        dbConnection = new DBConnection();

        System.out.println("Connecting to Database");
        try {
            dbConnection.initialize();
        } catch (SQLException e) {
            e.printStackTrace();
            try {
                dbConnection.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
        do {

            System.out.println("");
            System.out.println("1 - Consultar Cliente");
            System.out.println("2 - Consultar Fatura");
            System.out.println("3 - Popular Database");
            System.out.println("0 - Sair");
            System.out.print("Opcao: ");

            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    try {
                        consultaCliente();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                    break;
                case 2:
                    try {
                        consultaFatura();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    System.out.println("Populating Database");
                    try {
                        dbConnection.populate();
                    } catch (SQLException e) {
                        e.printStackTrace();
                        try {
                            dbConnection.close();
                        } catch (SQLException ex) {
                            ex.printStackTrace();
                        }
                        return;
                    }
                    break;
                case 0:
                    break;
            }

        } while (opcao != 0);

        try {
            dbConnection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void consultaCliente() throws SQLException {
        ArrayList<Cliente> foundClientes;

        scanner.nextLine();
        System.out.print("Digite o nome do cliente: ");
        String buffer = scanner.nextLine();

        foundClientes = dbConnection.searchClientByName(buffer);

        if (foundClientes.isEmpty()) {
            System.out.println("Nenhum Cliente encontrado");
            return;
        }

        System.out.println("Cliente(s) encontrado(s):");
        for (Cliente cliente : foundClientes) {
            System.out.println(cliente.toString());
        }
    }

    private static void consultaFatura() throws SQLException {
        int opcao;
        Cliente foundCliente;
        ArrayList<Cliente> foundClientes;
        ArrayList<Fatura> faturas;

        scanner.nextLine();
        System.out.print("Digite o nome do cliente: ");
        String buffer = scanner.nextLine();

        foundClientes = dbConnection.searchClientByName(buffer);

        if (foundClientes.isEmpty()) {
            System.out.println("Nenhum Cliente encontrado");
            return;
        }

        if(foundClientes.size() > 1) {
            System.out.println("Cliente(s) encontrado(s):");
            for (Cliente cliente : foundClientes) {
                System.out.println(cliente.toString());
            }

            System.out.print("Digite o ID do cliente escolhido: ");
            opcao = scanner.nextInt();

            foundCliente = dbConnection.getClientById(opcao);
        } else {
            foundCliente = foundClientes.get(0);
        }

        faturas = dbConnection.getFaturasByClientId(foundCliente.getId());

        if(faturas == null) {
            System.out.println("Nenhuma fatura encontrada");
            return;
        }

        System.out.println("Fatura(s) encontrada(s):");
        for (Fatura fatura : faturas) {
            System.out.println(fatura.toString());

            consultaLigacoes(fatura.getId());

            consultaInternet(fatura.getId());
        }
    }

    private static void consultaLigacoes(int id_fatura) throws SQLException {
        String line;

        System.out.print("Deseja visualizar as ligacoes desta fatura? [S/n] ");
        do {
            line = scanner.nextLine();
        } while (line.length() != 0 && line.charAt(0) != 's' && line.charAt(0) != 'n');

        if(line.length() != 0 && line.charAt(0) != 's')
            return;

        ArrayList<Ligacao> ligacoes = dbConnection.getLigacoesByFaturaId(id_fatura);

        if(ligacoes.isEmpty()) {
            System.out.println("Nenhuma ligacao encontrada");
            return;
        }

        for(Ligacao ligacao : ligacoes) {
            System.out.println(ligacao.toString());
        }
    }

    private static void consultaInternet(int id_fatura) throws SQLException {
        String line;

        System.out.print("Deseja visualizar o uso de internet desta fatura? [S/n] ");
        do {
            line = scanner.nextLine();
        } while (line.length() != 0 && line.charAt(0) != 's' && line.charAt(0) != 'n');

        if(line.length() != 0 && line.charAt(0) != 's')
            return;

        ArrayList<Internet> internetList = dbConnection.getInternetByFaturaId(id_fatura);

        if(internetList.isEmpty()) {
            System.out.println("Nenhum uso de internet encontrado");
            return;
        }

        for(Internet internet : internetList) {
            System.out.println(internet.toString());
        }
    }
}
