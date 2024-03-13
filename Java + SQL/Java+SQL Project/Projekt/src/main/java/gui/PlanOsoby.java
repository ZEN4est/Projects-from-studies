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

public class PlanOsoby extends JFrame {
    private JPanel panel1;
    private JRadioButton fizjoterapeutaRadioButton;
    private JRadioButton trenerRadioButton;
    private JRadioButton pilkarzRadioButton;
    private JTextField IDTextField;
    private JScrollPane poniedzialekPane;
    private JScrollPane wtorekPane;
    private JScrollPane piatekPane;
    private JScrollPane sobotaPane;
    private JScrollPane srodaPane;
    private JScrollPane czwartekPane;
    private JScrollPane niedzielaPane;
    private JScrollPane lista;
    private JButton wyswietlButton;
    private JButton powrotButton;

    public PlanOsoby(){
        setContentPane(panel1);
        setTitle("Plan osoby");
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
        JTextArea textLista = new JTextArea();
        textLista.setEditable(false);
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
        textCzwartek.setFont(new Font("Arial", Font.PLAIN, 11));
        textNiedziela.setFont(new Font("Arial", Font.PLAIN, 11));
        textPiatek.setFont(new Font("Arial", Font.PLAIN, 11));
        textSobota.setFont(new Font("Arial", Font.PLAIN, 11));
        textPoniedzalek.setFont(new Font("Arial", Font.PLAIN, 11));
        textWtorek.setFont(new Font("Arial", Font.PLAIN, 11));
        textSroda.setFont(new Font("Arial", Font.PLAIN, 11));
        textLista.setFont(new Font("Arial", Font.PLAIN, 11));
        lista.setViewportView(textLista);

        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Plan();
                dispose();
            }
        });


        wyswietlButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                Connection connection = base.connect();
                if(pilkarzRadioButton.isSelected()){
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try{
                        PreparedStatement pst = connection.prepareStatement("Select nazwa_sali, dzien_treningu from widok_treningu where trening_id in (select trening_id from trening_pilkarz where pilkarz_id = ?)");
                        pst.setInt(1,Integer.parseInt(IDTextField.getText()));
                        ResultSet rs = pst.executeQuery();
                        while(rs.next()){
                            switch (rs.getString("dzien_treningu")){
                                case ("Poniedziałek"):
                                    wypisPoniedzalek+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela+= "Trening \n  ("+ rs.getString("nazwa_sali")+")\n";
                                    break;
                                default:
                                    break;
                            }
                        }
                        PreparedStatement pst2 = connection.prepareStatement("Select fizjoterapeuta_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta where pilkarz_id = ?");
                        pst2.setInt(1,Integer.parseInt(IDTextField.getText()));
                        ResultSet rs2 = pst2.executeQuery();
                        while(rs2.next()){
                            switch (rs2.getString("dzien_cwiczen")){
                                case ("Poniedziałek"):
                                    wypisPoniedzalek+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela+= "Ćwiczenia:\n  " + rs2.getString("fizjoterapeuta_imie_nazwisko")+"\n";
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
                }else if(trenerRadioButton.isSelected()){
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try{
                        PreparedStatement pst = connection.prepareStatement("Select dzien_treningu, nazwa_sali, nazwa_sprzetu from widok_treningu where trener_id = ?");
                        pst.setInt(1,Integer.parseInt(IDTextField.getText()));
                        ResultSet rs = pst.executeQuery();
                        while(rs.next()){
                            switch (rs.getString("dzien_treningu")){
                                case ("Poniedziałek"):
                                    wypisPoniedzalek+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela+= "Trening\n("+ rs.getString("nazwa_sali")+"),\nsprzęt: "+rs.getString("nazwa_sprzetu")+"\n-------\n";
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
                }else if(fizjoterapeutaRadioButton.isSelected()){
                    String wypisPoniedzalek = "";
                    String wypisWtorek = "";
                    String wypisSroda = "";
                    String wypisCzwartek = "";
                    String wypisPiatek = "";
                    String wypisSobota = "";
                    String wypisNiedziela = "";

                    try{
                        PreparedStatement pst = connection.prepareStatement("Select dzien_cwiczen, pilkarz_imie_nazwisko from widok_cwiczenia_fizjoterapeuta where fizjoterapeuta_id = ?");
                        pst.setInt(1,Integer.parseInt(IDTextField.getText()));
                        ResultSet rs = pst.executeQuery();
                        while(rs.next()){
                            switch (rs.getString("dzien_cwiczen")){
                                case ("Poniedziałek"):
                                    wypisPoniedzalek+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
                                    break;
                                case ("Wtorek"):
                                    wypisWtorek+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
                                    break;
                                case ("Środa"):
                                    wypisSroda+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
                                    break;
                                case ("Czwartek"):
                                    wypisCzwartek+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
                                    break;
                                case ("Piątek"):
                                    wypisPiatek+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
                                    break;
                                case ("Sobota"):
                                    wypisSobota+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
                                    break;
                                case ("Niedziela"):
                                    wypisNiedziela+= "Zajęcia z:\n" + rs.getString("pilkarz_imie_nazwisko")+"\n-------\n";
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
                }
                base.closeConnection(connection);
            }
        });

        fizjoterapeutaRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                fizjoterapeutaRadioButton.setSelected(true);
                trenerRadioButton.setSelected(false);
                pilkarzRadioButton.setSelected(false);
                Connection connection = base.connect();
                String wypis ="Fizjoterapeuci:\n";
                try{
                    PreparedStatement fizjoterapeuci = connection.prepareStatement("SELECT fizjoterapeuta_id, imie, nazwisko from fizjoterapeuta ");
                    ResultSet fizjoRs = fizjoterapeuci.executeQuery();
                    while(fizjoRs.next()){
                        wypis += fizjoRs.getString("fizjoterapeuta_id") + " - " + fizjoRs.getString("imie") +" " + fizjoRs.getString("nazwisko")+"\n";
                    }
                    textLista.setText(wypis);

                }catch (SQLException ex){throw new RuntimeException(ex);}
                base.closeConnection(connection);
            }
        });

        trenerRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                fizjoterapeutaRadioButton.setSelected(false);
                trenerRadioButton.setSelected(true);
                pilkarzRadioButton.setSelected(false);
                Connection connection = base.connect();
                String wypis ="Fizjoterapeuci:\n";
                try{
                    PreparedStatement fizjoterapeuci = connection.prepareStatement("SELECT trener_id, imie, nazwisko from trener ");
                    ResultSet fizjoRs = fizjoterapeuci.executeQuery();
                    while(fizjoRs.next()){
                        wypis += fizjoRs.getString("trener_id") + " - " + fizjoRs.getString("imie") +" " + fizjoRs.getString("nazwisko")+"\n";
                    }
                    textLista.setText(wypis);

                }catch (SQLException ex){throw new RuntimeException(ex);}
                base.closeConnection(connection);
            }
        });

        pilkarzRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                fizjoterapeutaRadioButton.setSelected(false);
                trenerRadioButton.setSelected(false);
                pilkarzRadioButton.setSelected(true);
                Connection connection = base.connect();
                String wypis ="Fizjoterapeuci:\n";
                try{
                    PreparedStatement fizjoterapeuci = connection.prepareStatement("SELECT pilkarz_id, imie, nazwisko from pilkarz ");
                    ResultSet fizjoRs = fizjoterapeuci.executeQuery();
                    while(fizjoRs.next()){
                        wypis += fizjoRs.getString("pilkarz_id") + " - " + fizjoRs.getString("imie") +" " + fizjoRs.getString("nazwisko")+"\n";
                    }
                    textLista.setText(wypis);

                }catch (SQLException ex){throw new RuntimeException(ex);}
                base.closeConnection(connection);
            }
        });

    }
}
