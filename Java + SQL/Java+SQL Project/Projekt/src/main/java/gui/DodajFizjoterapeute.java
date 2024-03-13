package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DodajFizjoterapeute extends JFrame{
    private JPanel panel1;
    private JTextField imieField;
    private JTextField nazwiskoField;
    private JButton dodajButton;
    private JTextField zarobkiField;
    private JButton powrotButton;

    public DodajFizjoterapeute(){
        setContentPane(panel1);
        setTitle("Dodaj fizjoterapeute");
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
                try{
                    PreparedStatement pst = connection.prepareStatement("insert into fizjoterapeuta(imie, nazwisko,zarobki_za_trening) values (?,?,?)");
                    pst.setString(1,imieField.getText());
                    pst.setString(2,nazwiskoField.getText());
                    pst.setInt(3,Integer.parseInt(zarobkiField.getText()));
                    pst.executeUpdate();

                }catch (SQLException ex){throw new RuntimeException(ex);}
                base.closeConnection(connection);
                imieField.setText("");
                nazwiskoField.setText("");
                zarobkiField.setText("");
            }
        });
    }
}
