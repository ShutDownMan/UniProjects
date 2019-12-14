package com.company;

import java.io.FileInputStream;
import java.sql.*;

public class DBConnection {
    private static Connection dbConnection;

    /// Initialize database connection
    static void initialize() {
        Connection connection = null;

        /// Try creating a connection to the database
        try {
            Class.forName("org.postgresql.Driver");
            connection = DriverManager
                    .getConnection("jdbc:postgresql://localhost:5432/memorytaggerdb",
                            "postgres", "NotSafePasswd123");
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
        System.out.println("Opened database successfully");

        DBConnection.setDBConnection(connection);
    }

    public static Connection getDBConnection() {
        /// If connection doesn't exist
        if (dbConnection == null) {
            /// Create one
            DBConnection.initialize();
        }

        /// Return existing connection
        return dbConnection;
    }

    public static void setDBConnection(Connection dbConnection) {
        DBConnection.dbConnection = dbConnection;
    }

    public static void runUpdateStatement(String strSQL) {
        if (dbConnection == null)
            throw new RuntimeException("Connection to database not created!");

        try {
            Statement statement = dbConnection.createStatement();
            statement.executeUpdate(strSQL);
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void updateTable(String table, int id, String attribute, String value) {
        /// Create SQL statement to be run by the database
        String strSQL = "UPDATE " + table + " SET " + attribute + " = " + value + " WHERE id=" + id;

        /// If there's no connection to the database
        if (dbConnection == null)
            throw new RuntimeException("Connection to database not created!");

        /// Try running the SQL statement
        try {
            Statement statement = dbConnection.createStatement();
            statement.executeUpdate(strSQL);
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void updateTableByteA(String table, long id, String attribute, FileInputStream fis, long fisLength) {
        /// Create SQL statement to be run by the database
        String strSQL = "UPDATE " + table + " SET " + attribute + " =? WHERE id=" + id;

        PreparedStatement ps = null;
        try {
            ps = dbConnection.prepareStatement(strSQL);
            ps.setBinaryStream(1, fis, fisLength);
            ps.executeUpdate();
            ps.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void terminate() {
        try {
            dbConnection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
