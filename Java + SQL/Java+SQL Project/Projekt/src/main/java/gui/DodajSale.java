package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DodajSale extends JFrame{
    private JPanel panel1;
    private JTextField nazwaField;
    private JTextField kosztField;
    private JButton dodajButton;
    private JButton powrotButton;
    public DodajSale(){
        setContentPane(panel1);
        setTitle("Dodaj sale");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();


        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajAdmin();
                dispose();
            }
        });

        dodajButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection connection = base.connect();
                try {
                    PreparedStatement pst = connection.prepareStatement("insert into sala(nazwa,koszt) values (?,?)");
                    pst.setString(1, nazwaField.getText());
                    pst.setInt(2, Integer.parseInt(kosztField.getText()));
                    pst.executeUpdate();

                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                }
                base.closeConnection(connection);
                kosztField.setText("");
                nazwaField.setText("");

            }
        });
    }
}
