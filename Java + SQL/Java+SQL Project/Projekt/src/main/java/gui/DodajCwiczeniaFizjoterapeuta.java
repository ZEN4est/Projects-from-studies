package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DodajCwiczeniaFizjoterapeuta extends JFrame{
    private JPanel panel1;
    private JTextField pilkarzField;
    private JTextField fizjoterapeutaField;
    private JButton dodajButton;
    private JComboBox dzienTygodniaCombo;
    private JButton powrotButton;
    private JScrollPane pilkarzePane;
    private JScrollPane fizjoterapeuciPane;
    private JLabel error;

    public DodajCwiczeniaFizjoterapeuta(){
        setContentPane(panel1);
        setTitle("Dodaj ćwiczenia");
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

        JTextArea pilkarze = new JTextArea();
        JTextArea fizjoterapeuci = new JTextArea();
        pilkarze.setEditable(false);
        fizjoterapeuci.setEditable(false);

        Connection c = base.connect();
        String wypisPilkarze="";

        try{
            PreparedStatement pilkarzePst = c.prepareStatement("SELECT pilkarz_id, imie,nazwisko from pilkarz order by pilkarz_id asc ");
            ResultSet pilkarzeRs = pilkarzePst.executeQuery();
            while(pilkarzeRs.next()){
                wypisPilkarze+= pilkarzeRs.getString("pilkarz_id") + " - " + pilkarzeRs.getString("imie")+ " " + pilkarzeRs.getString("nazwisko")+"\n";
            }

        }catch (SQLException ex){throw new RuntimeException(ex);}

        pilkarze.setText(wypisPilkarze);
        pilkarzePane.setViewportView(pilkarze);
        base.closeConnection(c);



        dzienTygodniaCombo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection c = base.connect();
                String wypiszfizjoterapeuci="";

                try {
                    PreparedStatement fizjoterapeuciPst = c.prepareStatement("SELECT fizjoterapeuta_id, imie, nazwisko FROM fizjoterapeuta WHERE fizjoterapeuta_id NOT IN (SELECT fizjoterapeuta_id FROM cwiczenia_fizjoterapeuta WHERE dzien_cwiczen = ?)");
                    fizjoterapeuciPst.setString(1,dzienTygodniaCombo.getSelectedItem().toString());
                    ResultSet fizjoterapeuciRs = fizjoterapeuciPst.executeQuery();
                    while (fizjoterapeuciRs.next()) {
                        wypiszfizjoterapeuci += fizjoterapeuciRs.getString("fizjoterapeuta_id") + " - " + fizjoterapeuciRs.getString("imie") + " " + fizjoterapeuciRs.getString("nazwisko") + "\n";
                    }
                }catch (SQLException ex){throw new RuntimeException(ex);}

                fizjoterapeuci.setText(wypiszfizjoterapeuci);
                fizjoterapeuciPane.setViewportView(fizjoterapeuci);
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
                    PreparedStatement pst = connection.prepareStatement("insert into cwiczenia_fizjoterapeuta(pilkarz_id,fizjoterapeuta_id,dzien_cwiczen) values (?,?,?)");
                    pst.setInt(1,Integer.parseInt(pilkarzField.getText()));
                    pst.setInt(2,Integer.parseInt(fizjoterapeutaField.getText()));
                    pst.setString(3,dzienTygodniaCombo.getSelectedItem().toString());

                    pst.executeUpdate();

                }catch (SQLException ex){
                    error.setText("Błąd przy dodawaniu");
                    throw new RuntimeException(ex);}
                base.closeConnection(connection);
                pilkarzField.setText("");
                fizjoterapeutaField.setText("");

            }
        });
    }
}
