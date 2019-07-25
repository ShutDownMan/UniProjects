package javamailtests;

import java.security.Security;
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.*;

public class JavaMailPop3Reader {

    public static void main(String args[]) throws Exception {

        // mail server connection parameters
        String host = "pop.mail.yahoo.com";
        String user = "jesuistoiamigo";
        String password = "";

        // connect to my pop3 inbox
        Properties properties = System.getProperties();
        final String SSL_FACTORY = "javax.net.ssl.SSLSocketFactory";

//        Security.addProvider(new com.sun.net.ssl.internal.ssl.Provider());
        properties.setProperty("mail.pop3.socketFactory.class", SSL_FACTORY);
        properties.setProperty("mail.pop3.socketFactory.fallback", "false");
        properties.setProperty("mail.pop3.port", "995");
        properties.setProperty("mail.pop3.socketFactory.port", "995");
        properties.setProperty("mail.pop3.ssl.trust", host); // Trust all Servers
        URLName urln = new URLName("pop3", host, 995, null, user, password);

        Session session = Session.getInstance(properties, null);
        Store store = session.getStore(urln);

        store.connect();

        Folder inbox = store.getFolder("Inbox");
        inbox.open(Folder.READ_ONLY);

        // get the list of inbox messages
        Message[] messages = inbox.getMessages();

        if (messages.length == 0) System.out.println("No messages found.");

        for (int i = 0; i < messages.length; i++) {
            // stop after listing ten messages
            if (i > 10) {
                System.exit(0);
                inbox.close(true);
                store.close();
            }

            System.out.println("Message " + (i + 1));
            System.out.println("From : " + messages[i].getFrom()[0]);
            System.out.println("Subject : " + messages[i].getSubject());
            System.out.println("Sent Date : " + messages[i].getSentDate());
            System.out.println();
        }

        inbox.close(true);
        store.close();
    }
}

