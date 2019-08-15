package javamailtests;

import java.security.Security;
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.*;

public class JavaMailPop3Reader {

    public static void main(String args[]) throws Exception {

        // Parametros de conexão do servidor de email
        String host = "pop.mail.yahoo.com";
        String user = "jesuistoiamigo";
        String password = "faA2$%Cde!@#fa1356$#$%";
        String port = "995";

        // Setup das propriedades da conexão
        Properties properties = System.getProperties();
        final String SSL_FACTORY = "javax.net.ssl.SSLSocketFactory";

        Security.addProvider(new com.sun.net.ssl.internal.ssl.Provider());

        properties.setProperty("mail.pop3.socketFactory.class", SSL_FACTORY);
        properties.setProperty("mail.pop3.socketFactory.fallback", "false");
        properties.setProperty("mail.pop3.port", port);
        properties.setProperty("mail.pop3.socketFactory.port", port);
        properties.setProperty("mail.pop3.ssl.trust", host); // Trust all Servers

        // URL de conexão
        URLName urln = new URLName("pop3", host, Integer.valueOf(port), null, user, password);

        // Pedido de conexão
        Session session = Session.getInstance(properties, null);
        session.setDebug(true);
        Store store = session.getStore(urln);
        store.connect();

        Folder inbox = store.getFolder("Inbox");
        inbox.open(Folder.READ_ONLY);

        // Pega lista de mensagens inbox
        Message[] messages = inbox.getMessages();

        if (messages.length == 0) System.out.println("Nenehuma mensagem encontrada.");

        /// Pra cada mensagem na lista
        for (int i = 0; i < messages.length; i++) {
            // Para depois das 10 primeiras mensagens
            if (i > 10) {
                System.exit(0);
                inbox.close(true);
                store.close();
            }

            System.out.println("Mensagem " + (i + 1));
            System.out.println("De: " + messages[i].getFrom()[0]);
            System.out.println("Titulo: " + messages[i].getSubject());
            System.out.println("Data de envio: " + messages[i].getSentDate());

            System.out.println();
        }

        inbox.close(true);
        store.close();
    }
}

