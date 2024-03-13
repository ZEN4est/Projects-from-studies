package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Main extends JFrame{
    private JPanel mainPanel;
    private JButton button1;
    private JScrollPane output;
    private JComboBox wyborWartosci;
    private JButton button2;

    public Main() {
        setContentPane(mainPanel);
        setTitle("Klub piłkarski");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        JTextArea textArea = new JTextArea();
        Database base = new Database();
        output.setViewportView(textArea);

        wyborWartosci.addItem("Koszty");
        wyborWartosci.addItem("Nazwa");
        wyborWartosci.addItem("Liczba wypożyczeń");

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StronaStartowa();
                dispose();
            }
        });

        button1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.setText("");
                Connection connection = base.connect();
                String wybor ="";
                switch (wyborWartosci.getSelectedItem().toString()){
                    case "Koszty":
                        wybor = "koszt_tygodniowy";
                        break;
                    case "Nazwa":
                        wybor = "nazwa";
                    case "Liczba wypożyczeń":
                        wybor = "liczba_wypozyczen";
                    default:
                }

                try {
                    PreparedStatement pst = connection.prepareStatement("SELECT nazwa FROM widok_wydatki_miesieczne_sprzet");

                    ResultSet rs = pst.executeQuery();
                    String wypis = new String("");
                    while (rs.next())  {
                        String koszt    = rs.getString(wybor) ;
                        wypis += (koszt + "\n");
                        System.out.println(koszt) ;   }
                    textArea.setText(wypis);

                    rs.close();
                    pst.close();
                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                } finally{
                    base.closeConnection(connection);
                }

            }
        });



    }
    public static void main(String[] args) {
        new StronaStartowa();

    }

}
