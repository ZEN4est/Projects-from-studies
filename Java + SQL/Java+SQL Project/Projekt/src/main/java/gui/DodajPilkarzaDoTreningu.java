package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DodajPilkarzaDoTreningu extends JFrame{
    private JPanel panel1;
    private JTextField pilkarzField;
    private JTextField treningField;
    private JButton dodajButton;
    private JButton powrotButton;
    private JScrollPane pilkarzePane;
    private JScrollPane treningiPane;
    private JLabel error;

    public DodajPilkarzaDoTreningu(){
        setContentPane(panel1);
        setTitle("Dodaj piłakrza do treningu");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();

        JTextArea pilkarze = new JTextArea();
        JTextArea treningi = new JTextArea();
        pilkarze.setEditable(false);
        treningi.setEditable(false);

        Connection c = base.connect();
        String wypisPilkarze="";
        String wypiszTreningi="";
        try{
            PreparedStatement pilkarzePst = c.prepareStatement("SELECT pilkarz_id, imie,nazwisko, pozycja from pilkarz order by pilkarz_id asc ");
            ResultSet pilkarzeRs = pilkarzePst.executeQuery();
            PreparedStatement treningiPst = c.prepareStatement("SELECT  trening_id, dzien_treningu, trener_imie_nazwisko, specjalizacja from widok_treningu order by trening_id asc");
            ResultSet treningiRs = treningiPst.executeQuery();
            while(pilkarzeRs.next()){
                wypisPilkarze+= pilkarzeRs.getString("pilkarz_id") + " - " + pilkarzeRs.getString("imie")+ " " + pilkarzeRs.getString("nazwisko")+ ", " +pilkarzeRs.getString("pozycja") +"\n";
            }
            while (treningiRs.next()){
                wypiszTreningi += treningiRs.getString("trening_id") + " - " + treningiRs.getString("trener_imie_nazwisko")+ ", dzień: " +treningiRs.getString("dzien_treningu") + "\nSpecjalizacja: "+ treningiRs.getString("specjalizacja")+ "\n\n";
            }
        }catch (SQLException ex){throw new RuntimeException(ex);}

        pilkarze.setText(wypisPilkarze);
        treningi.setText(wypiszTreningi);
        pilkarzePane.setViewportView(pilkarze);
        treningiPane.setViewportView(treningi);
        base.closeConnection(c);

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
                    PreparedStatement pst = connection.prepareStatement("insert into trening_pilkarz(pilkarz_id,trening_id) values (?,?)");
                    pst.setInt(1,Integer.parseInt(pilkarzField.getText()));
                    pst.setInt(2,Integer.parseInt(treningField.getText()));

                    pst.executeUpdate();

                }catch (SQLException ex){
                    error.setText("Błąd przy dodawaniu");
                    throw new RuntimeException(ex);}
                base.closeConnection(connection);
                pilkarzField.setText("");
                treningField.setText("");

            }
        });
    }
}
