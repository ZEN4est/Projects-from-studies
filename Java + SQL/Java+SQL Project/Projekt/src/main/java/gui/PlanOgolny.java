package gui;

import logic.Database;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class PlanOgolny extends JFrame {


    private JPanel panel1;
    private JScrollPane poniedzialekPane;
    private JScrollPane wtorekPane;
    private JScrollPane srodaPane;
    private JScrollPane czwartekPane;
    private JScrollPane piatekPane;
    private JScrollPane sobotaPane;
    private JScrollPane niedzielaPane;
    private JButton powrotButton;
    private JCheckBox treningiCheckBox;
    private JCheckBox cwiczeniaCheckBox;

    public PlanOgolny(){
        setContentPane(panel1);
        setTitle("Plan ogólny");
        setSize(1000, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();
        JTextArea textPoniedzalek = new JTextArea();
        JTextArea textWtorek = new JTextArea();
        JTextArea textSroda = new JTextArea();
        JTextArea textCzwartek = new JTextArea();
        JTextArea textPiatek = new JTextArea();
        JTextArea textSobota = new JTextArea();
        JTextArea textNiedziela = new JTextArea();
        textNiedziela.setEditable(false);
        textWtorek.setEditable(false);
        textCzwartek.setEditable(false);
        textPiatek.setEditable(false);
        textSobota.setEditable(false);
        textPoniedzalek.setEditable(false);
        textSroda.setEditable(false);
        poniedzialekPane.setViewportView(textPoniedzalek);
        wtorekPane.setViewportView(textWtorek);
        srodaPane.setViewportView(textSroda);
        czwartekPane.setViewportView(textCzwartek);
        piatekPane.setViewportView(textPiatek);
        sobotaPane.setViewportView(textSobota);
        niedzielaPane.setViewportView(textNiedziela);
        textCzwartek.setFont(new Font("Arial", Font.PLAIN, 10));
        textNiedziela.setFont(new Font("Arial", Font.PLAIN, 10));
        textPiatek.setFont(new Font("Arial", Font.PLAIN, 10));
        textSobota.setFont(new Font("Arial", Font.PLAIN, 10));
        textPoniedzalek.setFont(new Font("Arial", Font.PLAIN, 10));
        textWtorek.setFont(new Font("Arial", Font.PLAIN, 10));
        textSroda.setFont(new Font("Arial", Font.PLAIN, 10));

        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Plan();
                dispose();
            }
        });

        cwiczeniaCheckBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection connection = base.connect();

                if (treningiCheckBox.isSelected() && !cwiczeniaCheckBox.isSelected()) {
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu from widok_treningu group by trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_treningu")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }
                        textCzwartek.setText(wypisCzwartek);
                        textNiedziela.setText(wypisNiedziela);
                        textPiatek.setText(wypisPiatek);
                        textPoniedzalek.setText(wypisPoniedzalek);
                        textSobota.setText(wypisSobota);
                        textWtorek.setText(wypisWtorek);
                        textSroda.setText(wypisSroda);

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }
                } else if (treningiCheckBox.isSelected() && cwiczeniaCheckBox.isSelected()) {
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu from widok_treningu group by trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_treningu")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }
                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta group by fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_cwiczen")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }

                    textCzwartek.setText(wypisCzwartek);
                    textNiedziela.setText(wypisNiedziela);
                    textPiatek.setText(wypisPiatek);
                    textPoniedzalek.setText(wypisPoniedzalek);
                    textSobota.setText(wypisSobota);
                    textWtorek.setText(wypisWtorek);
                    textSroda.setText(wypisSroda);
                } else if (!treningiCheckBox.isSelected() && cwiczeniaCheckBox.isSelected()) {
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";
                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta group by fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_cwiczen")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: " + rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }
                    textCzwartek.setText(wypisCzwartek);
                    textNiedziela.setText(wypisNiedziela);
                    textPiatek.setText(wypisPiatek);
                    textPoniedzalek.setText(wypisPoniedzalek);
                    textSobota.setText(wypisSobota);
                    textWtorek.setText(wypisWtorek);
                    textSroda.setText(wypisSroda);
                } else if (!treningiCheckBox.isSelected() && !cwiczeniaCheckBox.isSelected()) {
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";
                    textCzwartek.setText(wypisCzwartek);
                    textNiedziela.setText(wypisNiedziela);
                    textPiatek.setText(wypisPiatek);
                    textPoniedzalek.setText(wypisPoniedzalek);
                    textSobota.setText(wypisSobota);
                    textWtorek.setText(wypisWtorek);
                    textSroda.setText(wypisSroda);
                }
                base.closeConnection(connection);
            }
        });

        treningiCheckBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection connection = base.connect();

                if (treningiCheckBox.isSelected() && !cwiczeniaCheckBox.isSelected()){
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try{
                        PreparedStatement pst = connection.prepareStatement("SELECT trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu from widok_treningu group by trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu");
                        ResultSet rs = pst.executeQuery();

                        while(rs.next()){
                            switch (rs.getString("dzien_treningu")){
                                case ("Poniedziałek"):
                                    wypisPoniedzalek+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela+= "Trening\n"+"Prowadzący: "+ rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali")+"\nSprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }
                        textCzwartek.setText(wypisCzwartek);
                        textNiedziela.setText(wypisNiedziela);
                        textPiatek.setText(wypisPiatek);
                        textPoniedzalek.setText(wypisPoniedzalek);
                        textSobota.setText(wypisSobota);
                        textWtorek.setText(wypisWtorek);
                        textSroda.setText(wypisSroda);

                    }catch (SQLException ex){throw new RuntimeException(ex);}
                }else if(treningiCheckBox.isSelected() && cwiczeniaCheckBox.isSelected()) {
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu from widok_treningu group by trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_treningu")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Trening\n" + "Prowadzący: " + rs.getString("trener_imie_nazwisko") + "\nSpecjalizacja: " + rs.getString("specjalizacja") + "\nSala: " + rs.getString("nazwa_sali") + "\nSprzęt: " + rs.getString("nazwa_sprzetu") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }
                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta group by fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_cwiczen")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }

                    textCzwartek.setText(wypisCzwartek);
                    textNiedziela.setText(wypisNiedziela);
                    textPiatek.setText(wypisPiatek);
                    textPoniedzalek.setText(wypisPoniedzalek);
                    textSobota.setText(wypisSobota);
                    textWtorek.setText(wypisWtorek);
                    textSroda.setText(wypisSroda);
                } else if(!treningiCheckBox.isSelected() && cwiczeniaCheckBox.isSelected()){
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";
                    try {
                        PreparedStatement pst = connection.prepareStatement("SELECT fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta group by fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen");
                        ResultSet rs = pst.executeQuery();

                        while (rs.next()) {
                            switch (rs.getString("dzien_cwiczen")) {
                                case ("Poniedziałek"):
                                    wypisPoniedzalek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela += "Ćwiczenia\nProwadzący: " + rs.getString("fizjoterapeuta_imie_nazwisko") + "\nPiłkarz: "+ rs.getString("pilkarz_imie_nazwisko") + "\n-------\n";
                                    break;
                                default:
                                    break;
                            }
                        }

                    } catch (SQLException ex) {
                        throw new RuntimeException(ex);
                    }
                    textCzwartek.setText(wypisCzwartek);
                    textNiedziela.setText(wypisNiedziela);
                    textPiatek.setText(wypisPiatek);
                    textPoniedzalek.setText(wypisPoniedzalek);
                    textSobota.setText(wypisSobota);
                    textWtorek.setText(wypisWtorek);
                    textSroda.setText(wypisSroda);
                }else if(!treningiCheckBox.isSelected() && !cwiczeniaCheckBox.isSelected()){
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";
                    textCzwartek.setText(wypisCzwartek);
                    textNiedziela.setText(wypisNiedziela);
                    textPiatek.setText(wypisPiatek);
                    textPoniedzalek.setText(wypisPoniedzalek);
                    textSobota.setText(wypisSobota);
                    textWtorek.setText(wypisWtorek);
                    textSroda.setText(wypisSroda);
                }
                base.closeConnection(connection);
            }
        });






    }
}
