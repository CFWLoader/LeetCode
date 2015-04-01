package evan.server.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * Created by cfwloader on 4/1/15.
 */
public class MySQLConnectionGenerator {

    static{
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    static public Connection getConnection(){
        try {
            return DriverManager.getConnection("jdbc:mysql://localhost:3306/chatroom","clown","123456");
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
