package logic;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class Database {

    private final String url = "jdbc:postgresql://trumpet.db.elephantsql.com:5432/urzwahar";
    private final String user = "urzwahar";
    private final String password = "uGefvBlO368pC9eC49sReBwrRKAzA9YH";
    public Connection connect() {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return connection;
    }

    public void closeConnection(Connection connection) {
        try {
            connection.close();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}
