package com.company;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class Main {

    static String[] statements = {
            /// Inserção dos usuários
            "INSERT INTO public.user (name, email, birthdate) VALUES " +
                    "('Paulo', 'email1@gmail.com', '1999-01-08')," +
                    "('Waldo', 'email2@hotmail.com', '2005-11-10')," +
                    "('Jonas', 'email3@yahoo.com', '1998-06-15');",
            /// Quais os usuários seguidores
            "INSERT INTO public.follow (id_user, id_user1) VALUES " +
                    "(1, 2)," +
                    "(1, 3)," +
                    "(3, 1);",
            /// As memórias dos usuários
            "INSERT INTO public.memory (title, description, id_user, submitted_time, user_visibility) VALUES " +
                    "('Memory one', 'This first memory', 1, '2004-10-19 10:23:54-03', 'Public'), " +
                    "('Memory two', 'Second memory', 1, '2004-10-19 10:24:59-03', 'FollowOnly'), " +
                    "('This day', 'I like it', 2, '2016-03-05 08:42:23-03', 'Private'), " +
                    "('', '', 2, '2016-03-06 21:31:18-03', 'Private'), " +
                    "('Oh no', 'Not cool', 2, '2016-03-06 22:12:03-03', 'Public'), " +
                    "('This song', 'Est geniaux', 3, '2019-05-09 05:42:24-03', 'Whitelist');",
            /// as tags criadas pelos usuários
            "INSERT INTO public.tag (name) VALUES " +
                    "('happy'), " +
                    "('crazy'), " +
                    "('wholesome'), " +
                    "('easy'), " +
                    "('fresh'), " +
                    "('cool'), " +
                    "('family'), " +
                    "('friends'), " +
                    "('calm');",
            /// as tags dadas as memórias
            "INSERT INTO public.memory_tag (id_memory, id_tag) VALUES " +
                    "(1, 4), " +
                    "(1, 2), " +
                    "(1, 6), " +
                    "(2, 1), " +
                    "(2, 2), " +
                    "(3, 4), " +
                    "(3, 9), " +
                    "(4, 5), " +
                    "(4, 4), " +
                    "(4, 2), " +
                    "(5, 2), " +
                    "(5, 3), " +
                    "(6, 7), " +
                    "(6, 5)"
    };

    static String[] memoryData = {
            "./memoryData/cat.png",
            "./memoryData/dog.jpg",
            "./memoryData/MOVIE.mp4",
            "./memoryData/Darude - Sandstorm.mp3",
            "./memoryData/jasfckjbsfa.txt",
            "./memoryData/img.png",
            "./memoryData/MAX - Love Me Less.mp3"
    };

    public static void main(String[] args) {
        /// Initializing database connection
        DBConnection.initialize();

        /// For each statement in the array
        for (String statement : statements) {
            System.out.println("[" + statement + "]");

            /// Run it
            DBConnection.runUpdateStatement(statement);
        }

        /// For each memory added to the database
        for (int i = 0; i < 6; ++i) {
            /// Get file
            File file = new File(memoryData[i]);
            FileInputStream fis = null;

            /// Try inserting it into the database
            try {
                /// Get file as InputStream
                fis = new FileInputStream(file);

                System.out.println("FILENAME: " + file.getName());
                /// Get file extension
                String ext = getFileExtension(file.getName());

                /// Update each memory to add it's file
                DBConnection.updateTableByteA("memory", i + 1, "data", fis, file.length());

                /// Add file metadata ass well
                DBConnection.updateTable("memory", i + 1, "metadata", "ROW ( '" + ext + "', " + file.length() + " ,'" + file.getName() + "')");

                /// Close InputStream
                fis.close();

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        /// Terminating database connection
        DBConnection.terminate();
    }

    /// Returns a file extension given its name
    private static String getFileExtension(String fileName) {
        if (fileName.lastIndexOf(".") != -1 && fileName.lastIndexOf(".") != 0)
            return fileName.substring(fileName.lastIndexOf(".") + 1);
        else return "";
    }

}
