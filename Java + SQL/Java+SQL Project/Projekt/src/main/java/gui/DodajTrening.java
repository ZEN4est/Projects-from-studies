package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DodajTrening extends JFrame{
    private JPanel panel1;
    private JTextField trenerIdField;
    private JTextField salaIdField;
    private JTextField sprzetIdField;
    private JComboBox dzienTygodniaCombo;
    private JButton dodajButton;
    private JButton powrotButton;
    private JScrollPane trenerzyPane;
    private JScrollPane salePane;
    private JScrollPane sprzetPane;
    private JLabel error;

    public DodajTrening(){
        setContentPane(panel1);
        setTitle("Dodaj trening");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();
        dzienTygodniaCombo.addItem("");
        dzienTygodniaCombo.addItem("Poniedziałek");
        dzienTygodniaCombo.addItem("Wtorek");
        dzienTygodniaCombo.addItem("Środa");
        dzienTygodniaCombo.addItem("Czwartek");
        dzienTygodniaCombo.addItem("Piątek");
        dzienTygodniaCombo.addItem("Sobota");
        dzienTygodniaCombo.addItem("Niedziela");

        JTextArea trenerzy = new JTextArea();
        JTextArea sale = new JTextArea();
        JTextArea sprzet = new JTextArea();
        trenerzy.setEditable(false);
        sale.setEditable(false);
        sprzet.setEditable(false);

        dzienTygodniaCombo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection c = base.connect();
                String wypisTrenerzy="";
                String wypisSale="";
                String wypisSprzet="";

                try {
                    PreparedStatement TrenerzyPst = c.prepareStatement("SELECT trener_id, imie, nazwisko FROM trener WHERE trener_id NOT IN (SELECT trener_id FROM trening WHERE dzien_treningu = ?)");
                    TrenerzyPst.setString(1,dzienTygodniaCombo.getSelectedItem().toString());
                    ResultSet TrenerzyRs = TrenerzyPst.executeQuery();
                    while (TrenerzyRs.next()) {
                        wypisTrenerzy += TrenerzyRs.getString("trener_id") + " - " + TrenerzyRs.getString("imie") + " " + TrenerzyRs.getString("nazwisko") + "\n";
                    }
                }catch (SQLException ex){throw new RuntimeException(ex);}

                try {
                    PreparedStatement SalePst = c.prepareStatement("SELECT sala_id,nazwa,koszt FROM sala WHERE sala_id NOT IN (SELECT sala_id FROM trening WHERE dzien_treningu = ?)");
                    SalePst.setString(1,dzienTygodniaCombo.getSelectedItem().toString());
                    ResultSet SaleRs = SalePst.executeQuery();
                    while (SaleRs.next()) {
                        wypisSale += SaleRs.getString("sala_id") + " - " + SaleRs.getString("nazwa") + ", koszt: " + SaleRs.getString("koszt") + "\n";
                    }
                }catch (SQLException ex){throw new RuntimeException(ex);}

                try {
                    PreparedStatement SprzetPst = c.prepareStatement("SELECT sprzet_id,nazwa,koszt FROM sprzet WHERE sprzet_id NOT IN (SELECT sprzet_id FROM trening WHERE dzien_treningu = ?)");
                    SprzetPst.setString(1,dzienTygodniaCombo.getSelectedItem().toString());
                    ResultSet SprzetRs = SprzetPst.executeQuery();
                    while (SprzetRs.next()) {
                        wypisSprzet += SprzetRs.getString("sprzet_id") + " - " + SprzetRs.getString("nazwa")  + ", koszt: " + SprzetRs.getString("koszt") + "\n";
                    }
                }catch (SQLException ex){throw new RuntimeException(ex);}

                trenerzy.setText(wypisTrenerzy);
                sale.setText(wypisSale);
                sprzet.setText(wypisSprzet);
                trenerzyPane.setViewportView(trenerzy);
                salePane.setViewportView(sale);
                sprzetPane.setViewportView(sprzet);
                base.closeConnection(c);

            }
        });



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
                    error.setText("");
                    PreparedStatement pst = connection.prepareStatement("insert into trening(trener_id,sala_id,sprzet_id,dzien_treningu) values (?,?,?,?)");
                    pst.setInt(1,Integer.parseInt(trenerIdField.getText()));
                    pst.setInt(2,Integer.parseInt(salaIdField.getText()));
                    pst.setInt(3,Integer.parseInt(sprzetIdField.getText()));
                    pst.setString(4,dzienTygodniaCombo.getSelectedItem().toString());
                    pst.executeUpdate();
                }catch (SQLException ex){
                    error.setText("Błąd przy dodawaniu");
                    throw new RuntimeException(ex);}
                base.closeConnection(connection);
                trenerIdField.setText("");
                salaIdField.setText("");
                sprzetIdField.setText("");
            }
        });
    }
}
