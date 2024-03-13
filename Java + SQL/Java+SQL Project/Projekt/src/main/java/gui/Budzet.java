package gui;

import logic.Database;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Budzet extends JFrame{
    private JComboBox rodzajCombo;
    private JButton powrotButton;
    private JPanel panel1;
    private JScrollPane tabelaScrollPane;
    private JLabel text;
    private JPanel panel2;

    public Budzet() {
        setContentPane(panel2);
        setTitle("Budżet");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();
        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);
        tabelaScrollPane.setViewportView(textArea);


        rodzajCombo.addItem("");
        rodzajCombo.addItem("Treningi");
        rodzajCombo.addItem("Ćwiczenia");
        rodzajCombo.addItem("Trenerzy");
        rodzajCombo.addItem("Fizjoterapeuci");
        rodzajCombo.addItem("Sale");
        rodzajCombo.addItem("Sprzęt");

        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StronaStartowa();
                dispose();
            }
        });


        rodzajCombo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection connection = base.connect();
                String wypis =new String("");
                switch (rodzajCombo.getSelectedItem().toString()){
                    case("Treningi"):
                        wypis="Tygodniowe wydatki na treningi\n";
                        try{
                            PreparedStatement TreningKoszt = connection.prepareStatement("Select SUM(koszt_sali) as koszt_sali,SUM(koszt_sprzetu) as koszt_sprzetu, SUM(zarobki_za_trening) as koszt_trenerow from widok_treningu");
                            ResultSet TreningKosztRs = TreningKoszt.executeQuery();
                            TreningKosztRs.next();
                            wypis+="Tygodniowe wydatki na sprzęt: "+ TreningKosztRs.getString("koszt_sprzetu") +"\nTygodniowe wydatki na sale: " + TreningKosztRs.getString("koszt_sali")+"\nTygodniowe wydatki na pensje trenerów: "+ TreningKosztRs.getString("koszt_trenerow")+"\n";
                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        try{
                            PreparedStatement lacznyKoszt = connection.prepareStatement("SELECT  * from widok_wydatki_tygodniowe_treningi");
                            ResultSet lacznyKosztRs = lacznyKoszt.executeQuery();
                            wypis+= "=================\nŁączne wydatki na treningi:\n";
                            while(lacznyKosztRs.next()){
                                wypis+= lacznyKosztRs.getString("koszt_tygodniowy_treningow") +"\n";
                            }
                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        textArea.setText(wypis);
                        break;
                    case("Ćwiczenia"):
                        wypis="Tygodniowe wydatki na ćwiczenia fizjoterapeutyczne\n";
                        try{
                            PreparedStatement kosztCwiczen = connection.prepareStatement("SELECT  SUM(zarobki_za_trening) as zarobki_za_trening from widok_cwiczenia_fizjoterapeuta");
                            ResultSet kosztCwiczenRs = kosztCwiczen.executeQuery();
                            kosztCwiczenRs.next();
                            wypis += kosztCwiczenRs.getString("zarobki_za_trening");

                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        textArea.setText(wypis);

                        break;
                    case("Trenerzy"):
                        wypis = "Tygodniowe wydatki na Trenerów\n";
                        try{
                            PreparedStatement wydatkiNaTrenerow = connection.prepareStatement("select * from widok_wydatki_tygodniowe_trenerzy");
                            ResultSet wydatkiNaTrenerowRs = wydatkiNaTrenerow.executeQuery();
                            while(wydatkiNaTrenerowRs.next()){
                                wypis+= wydatkiNaTrenerowRs.getString("trener_imie_nazwisko")+" (treningów: "+ wydatkiNaTrenerowRs.getString("liczba_treningow") + "), tygodniowe zarobki: "+ wydatkiNaTrenerowRs.getString("koszt_tygodniowy")+"\n";
                            }
                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        try{
                            PreparedStatement laczneZarobki = connection.prepareStatement("SELECT SUM(zarobki_za_trening) as koszt_trenerow from widok_treningu");
                            ResultSet laczneZarobkiRs = laczneZarobki.executeQuery();
                            laczneZarobkiRs.next();
                            wypis+= "=================\nŁączne zarobki trenerów: "+ laczneZarobkiRs.getString("koszt_trenerow");

                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        textArea.setText(wypis);
                        break;
                    case ("Sale"):
                        wypis = "Tygodniowe wydatki na Sale\n";
                        try{
                            PreparedStatement wydatkiNaSale = connection.prepareStatement("select * from widok_wydatki_tygodniowe_sala");
                            ResultSet wydatkiNaSaleRs = wydatkiNaSale.executeQuery();
                            while(wydatkiNaSaleRs.next()){
                                wypis+= wydatkiNaSaleRs.getString("nazwa_sali")+" (wynajęć: "+ wydatkiNaSaleRs.getString("liczba_wynajec") + "), koszt tygodniowy: "+ wydatkiNaSaleRs.getString("koszt_tygodniowy")+"\n";
                            }
                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        try{
                            PreparedStatement lacznyKosztSali = connection.prepareStatement("SELECT SUM(koszt_sali) as koszt_sali from widok_treningu");
                            ResultSet lacznyKosztSaliRs = lacznyKosztSali.executeQuery();
                            lacznyKosztSaliRs.next();
                            wypis+= "=================\nŁączne wydatki na sale: "+ lacznyKosztSaliRs.getString("koszt_sali");

                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        textArea.setText(wypis);
                        break;
                    case ("Sprzęt"):
                        wypis = "Tygodniowe wydatki na Sprzet\n";
                        try{
                            PreparedStatement wydatkiNaSprzet = connection.prepareStatement("select * from widok_wydatki_tygodniowe_sprzet");
                            ResultSet wydatkiNaSprzetRs = wydatkiNaSprzet.executeQuery();
                            while(wydatkiNaSprzetRs.next()){
                                wypis+= wydatkiNaSprzetRs.getString("nazwa_sprzetu")+" (wynajęć: "+ wydatkiNaSprzetRs.getString("liczba_wypozyczen") + "), koszt tygodniowy: "+ wydatkiNaSprzetRs.getString("koszt_tygodniowy")+"\n";
                            }
                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        try{
                            PreparedStatement lacznyKosztSprzetu = connection.prepareStatement("SELECT SUM(koszt_sprzetu) as koszt_sprzetu from widok_treningu");
                            ResultSet lacznyKosztSprzetuRs = lacznyKosztSprzetu.executeQuery();
                            lacznyKosztSprzetuRs.next();
                            wypis+= "=================\nŁączne wydatki na sprzęt: "+ lacznyKosztSprzetuRs.getString("koszt_sprzetu");

                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        textArea.setText(wypis);
                        break;
                    case("Fizjoterapeuci"):
                        wypis = "Tygodniowe wydatki na fizjoterapeutów\n";
                        try{
                            PreparedStatement wydatkiNaFizjoterapeutow = connection.prepareStatement("select * from widok_wydatki_tygodniowe_fizjoterapeuta");
                            ResultSet wydatkiNaFizjoterapeutowRs = wydatkiNaFizjoterapeutow.executeQuery();
                            while(wydatkiNaFizjoterapeutowRs.next()){
                                wypis+= wydatkiNaFizjoterapeutowRs.getString("fizjoterapeuta_imie_nazwisko")+" (zajęć: "+ wydatkiNaFizjoterapeutowRs.getString("liczba_zajec_fizjoterapeutycznych") + "), tygodniowe zarobki: "+ wydatkiNaFizjoterapeutowRs.getString("koszt_tygodniowy")+"\n";
                            }
                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        try{
                            PreparedStatement laczneZarobkiFizjo = connection.prepareStatement("SELECT SUM(zarobki_za_trening) as koszt_fizjoterapeutow from widok_cwiczenia_fizjoterapeuta");
                            ResultSet laczneZarobkiFizjoRs = laczneZarobkiFizjo.executeQuery();
                            laczneZarobkiFizjoRs.next();
                            wypis+= "=================\nŁączne zarobki fizjoterapeutów: "+ laczneZarobkiFizjoRs.getString("koszt_fizjoterapeutow");

                        }catch (SQLException ex){
                            throw new RuntimeException(ex);
                        }
                        textArea.setText(wypis);
                        break;
                    default:
                        break;
                }
                base.closeConnection(connection);

            }
        });



    }
}
