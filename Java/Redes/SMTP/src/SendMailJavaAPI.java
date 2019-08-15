import org.omg.CORBA.TRANSACTION_MODE;

import java.security.Security;
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

public class SendMailJavaAPI {

    public static void main(String[] args) throws Exception{

        String host = "smtp.mail.yahoo.com";
        String port = "465";
        String user = "jesuistoiamigo";
        String password = "faA2$%Cde!@#fa1356$#$%";

        // de e para
        String to = "jesuistoiamigo@yahoo.com";
        String from = "jesuistoiamigo@yahoo.com";

        Properties properties = System.getProperties();
        final String SSL_FACTORY = "javax.net.ssl.SSLSocketFactory";

        Security.addProvider(new com.sun.net.ssl.internal.ssl.Provider());

        properties.setProperty("mail.smtp.socketFactory.class", SSL_FACTORY);
        properties.setProperty("mail.smtp.socketFactory.fallback", "false");
        properties.setProperty("mail.smtp.port", port);
        properties.setProperty("mail.smtp.socketFactory.port", port);
        properties.setProperty("mail.smtp.auth", "true");
        properties.setProperty("mail.smtp.ssl.trust", host); // Trust all Servers

        // URL de conexão
        URLName urln = new URLName("smtp", host, Integer.valueOf(port), null, user, password);

        Session session = Session.getInstance(properties, null);
        session.setDebug(true);
        Transport transport = session.getTransport(urln);
        transport.connect();

        String msgBody = "Sending email using JavaMail API...";

        try {
            Message msg = new MimeMessage(session);
            Address[] addresses = {};
            msg.setFrom(new InternetAddress(from, "NoReply"));
            msg.addRecipient(Message.RecipientType.TO,
                    new InternetAddress(to, "Mr. Recipient"));
            addresses.
            msg.setSubject("Welcome To Java Mail API");
            msg.setText(msgBody);
            transport.sendMessage(msg, );
            System.out.println("Email sent successfully...");

        } catch (MessagingException e) {
            throw new RuntimeException(e);
        }
    }
}