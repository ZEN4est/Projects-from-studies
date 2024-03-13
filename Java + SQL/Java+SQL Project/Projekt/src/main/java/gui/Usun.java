package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Usun extends JFrame{
    private JPanel panel1;
    private JComboBox tabelaCombo;
    private JTextField IdField;
    private JButton usunButton;
    private JButton powrotButton;
    private JScrollPane listaPane;

    public  Usun(){
        setContentPane(panel1);
        setTitle("Usuń");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();
        tabelaCombo.addItem("");
        tabelaCombo.addItem("Piłkarz");
        tabelaCombo.addItem("Trener");
        tabelaCombo.addItem("Fizjoterapeuta");
        tabelaCombo.addItem("Sala");
        tabelaCombo.addItem("Sprzęt");
        tabelaCombo.addItem("Trening");
        tabelaCombo.addItem("Ćwiczenia Fizjoterapeutyczne");
        tabelaCombo.addItem("Wypisz piłkarza z treningu");

        JTextArea lista = new JTextArea();
        lista.setEditable(false);



        tabelaCombo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection c = base.connect();
                String wypisLista="";
                switch (tabelaCombo.getSelectedItem().toString()){
                    case ("Piłkarz"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT pilkarz_id, imie,nazwisko from pilkarz");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("pilkarz_id") + " - " + rs.getString("imie")+ " " + rs.getString("nazwisko")+"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Trener"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT trener_id, imie,nazwisko from trener");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("trener_id") + " - " + rs.getString("imie")+ " " + rs.getString("nazwisko")+"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Fizjoterapeuta"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT fizjoterapeuta_id, imie,nazwisko from fizjoterapeuta");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("fizjoterapeuta_id") + " - " + rs.getString("imie")+ " " + rs.getString("nazwisko")+"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Sala"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT sala_id, nazwa from sala");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("sala_id") + " - " + rs.getString("nazwa")+"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Sprzęt"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT sprzet_id, nazwa from sprzet");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("sprzet_id") + " - " + rs.getString("nazwa")+"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Trening"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT trening_id, dzien_treningu, trener_imie_nazwisko from widok_treningu");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("trening_id") + " - " + rs.getString("dzien_treningu")+ "  "+rs.getString("trener_imie_nazwisko") +"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Ćwiczenia Fizjoterapeutyczne"):
                        try{
                            PreparedStatement pst = c.prepareStatement("SELECT cwiczenia_fizjoterapeuta_id, dzien_cwiczen from cwiczenia_fizjoterapeuta");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("cwiczenia_fizjoterapeuta_id") + " - " + rs.getString("dzien_cwiczen")+"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Wypisz piłkarza z treningu"):
                        try{
                            PreparedStatement pst = c.prepareStatement("Select tp.trening_pilkarz_id ,wk.trener_imie_nazwisko,p.imie, p.nazwisko from widok_treningu wk join trening_pilkarz tp on wk.trening_id = tp.trening_id join pilkarz p on p.pilkarz_id = tp.pilkarz_id group by tp.trening_pilkarz_id, wk.trener_imie_nazwisko, p.imie, p.nazwisko order by tp.trening_pilkarz_id");
                            ResultSet rs = pst.executeQuery();
                            while(rs.next()){
                                wypisLista+= rs.getString("trening_pilkarz_id") + " - " + rs.getString("imie")+ " "+rs.getString("nazwisko")+ ", trener: "+ rs.getString("trener_imie_nazwisko") +"\n";
                            }
                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    default:
                        break;
                }
                lista.setText(wypisLista);
                listaPane.setViewportView(lista);
                base.closeConnection(c);
            }
        });

        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Admin();
                dispose();
            }
        });

        usunButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection c = base.connect();
                try{
                    String kolumna="";
                    String tabela ="";

                    switch (tabelaCombo.getSelectedItem().toString()){
                        case ("Piłkarz"):
                            kolumna = "pilkarz_id";
                            tabela = "pilkarz";
                            break;
                        case ("Trener"):
                            kolumna = "trener_id";
                            tabela = "trener";
                            break;
                        case ("Fizjoterapeuta"):
                            kolumna = "fizjoterapeuta_id";
                            tabela = "fizjoterapeuta";
                            break;
                        case ("Trening"):
                            kolumna = "trening_id";
                            tabela = "trening";
                            break;
                        case ("Sala"):
                            kolumna = "sala_id";
                            tabela = "sala";
                            break;
                        case ("Sprzęt"):
                            kolumna = "sprzet_id";
                            tabela = "sprzet";
                            break;
                        case ("Ćwiczenia Fizjoterapeutyczne"):
                            kolumna = "cwiczenia_fizjoterapeuta_id";
                            tabela = "cwiczenia_fizjoterapeuta";
                            break;
                        case ("Wypisz piłkarza z treningu"):
                            kolumna = "trening_pilkarz_id";
                            tabela = "trening_pilkarz";
                            break;
                        default:
                            break;
                    }
                    PreparedStatement pst = c.prepareStatement("delete from " + tabela+" where "+ kolumna+ " = ?");
                    pst.setInt(1,Integer.parseInt(IdField.getText()));

                    pst.executeUpdate();
                }catch (SQLException ex){throw new RuntimeException(ex);}
                IdField.setText("");
                base.closeConnection(c);
            }
        });


    }
}
