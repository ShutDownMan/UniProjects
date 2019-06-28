package jedson;

import jedson.DBObjects.Curso;

import java.io.IOException;
import java.sql.PreparedStatement;
import java.util.ArrayList;

import static java.lang.Compiler.command;

public class CadastroNovoAluno {
    private static MatriculasDB matriculasDB = null;

    public static void matricularNovoAluno() throws IOException, InterruptedException {
        matriculasDB = MatriculasDB.getInstance();
        matriculasDB.initialize();

        Main.cmdCommand("cls");

        showCursos();

    }

    private static void showCursos() {
        ArrayList<Curso> cursoList = matriculasDB.getCursos("");

        for (Curso curso : cursoList) {
            System.out.printf("%s\n", curso.toString());
        }
    }

}
