package jedson;

import jedson.DBObjects.Curso;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class MatriculasDB {
    private static MatriculasDB instance;
    private Connection con = null;

    private MatriculasDB() {
    }

    public static MatriculasDB getInstance() {
        if (instance == null) {
            instance = new MatriculasDB();
        }
        return instance;
    }

    void initialize() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/matriculas?useTimezone=true&serverTimezone=UTC", "Jedson", "Um23456sete");
        } catch (SQLException | ClassNotFoundException e1) {
            e1.printStackTrace();
        }
    }

    public ArrayList<Curso> getCursos(String restrictions) {
        ArrayList<Curso> result = new ArrayList<>();

        if (restrictions.isEmpty()) {
            try {
                PreparedStatement ps = con.prepareStatement("select * from matriculas.curso");
                ResultSet rs = ps.executeQuery();
                while (rs.next()) {
                    System.out.println(rs.getString(1));
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return result;
    }


}
