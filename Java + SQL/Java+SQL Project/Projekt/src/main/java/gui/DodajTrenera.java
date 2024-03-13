package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DodajTrenera extends JFrame {
    private JPanel panel1;
    private JTextField imieField;
    private JTextField nazwiskoField;
    private JComboBox pozycjaCombo;
    private JButton dodajButton;
    private JTextField zarobkiField;
    private JButton powrotButton;

    public DodajTrenera(){
        setContentPane(panel1);
        setTitle("Dodaj trenera");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();

        pozycjaCombo.addItem("");
        pozycjaCombo.addItem("Bramkarz");
        pozycjaCombo.addItem("Obrońca");
        pozycjaCombo.addItem("Pomocnik");
        pozycjaCombo.addItem("Napastnik");

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
                    PreparedStatement pst = connection.prepareStatement("insert into trener(imie, nazwisko, specjalizacja,zarobki_za_trening) values (?,?,?,?)");
                    pst.setString(1,imieField.getText());
                    pst.setString(2,nazwiskoField.getText());
                    pst.setString(3,pozycjaCombo.getSelectedItem().toString());
                    pst.setInt(4,Integer.parseInt(zarobkiField.getText()));
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
