package gui;

import logic.Database;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class WyswietlDane extends JFrame{
    private JPanel panel1;
    private JComboBox comboBox1;
    private JScrollPane tabelaScrollPane;
    private JButton powrotButton;

    public  WyswietlDane(){
        setContentPane(panel1);
        setTitle("Wyświetl dane");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
        Database base = new Database();
        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);
        tabelaScrollPane.setViewportView(textArea);
        comboBox1.addItem("");
        comboBox1.addItem("Trenerzy");
        comboBox1.addItem("Piłkarze");
        comboBox1.addItem("Sale");
        comboBox1.addItem("Sprzęt");
        comboBox1.addItem("Fizjoterapeuci");
        comboBox1.addItem("Treningi");
        comboBox1.addItem("Treningi piłkarzy");
        comboBox1.addItem("Ćwiczenia fizjoterapeutyczne");


        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new StronaStartowa();
                dispose();
            }
        });



        comboBox1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Connection connection = base.connect();
                Border trenerzyBorder = BorderFactory.createEtchedBorder();
                switch (comboBox1.getSelectedItem().toString()){
                    case("Trenerzy") :
                        Border trenerzyBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "Trener");
                        tabelaScrollPane.setBorder(trenerzyBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from trener",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"trener_id", "imie", "nazwisko","specjalizacja","zarobki_za_trening"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][5];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("trener_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("imie");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("nazwisko");
                                data[TrenerzyRs.getRow()-1][3] = TrenerzyRs.getString("specjalizacja");
                                data[TrenerzyRs.getRow()-1][4] = TrenerzyRs.getString("zarobki_za_trening");
                            }while(TrenerzyRs.next());


                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Fizjoterapeuci") :
                        Border fizjoBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "Fizjoterapeuta");
                        tabelaScrollPane.setBorder(fizjoBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from fizjoterapeuta",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"fizjoterapeuta_id", "imie", "nazwisko","zarobki_za_trening"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][4];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("fizjoterapeuta_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("imie");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("nazwisko");
                                data[TrenerzyRs.getRow()-1][3] = TrenerzyRs.getString("zarobki_za_trening");
                            }while(TrenerzyRs.next());


                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Sale") :
                        Border saleBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "Sala");
                        tabelaScrollPane.setBorder(saleBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from sala",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"sala_id", "nazwa", "koszt"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][3];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("sala_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("nazwa");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("koszt");
                            }while(TrenerzyRs.next());

                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Sprzęt") :
                        Border sprzetBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "Sprzęt");
                        tabelaScrollPane.setBorder(sprzetBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from sprzet",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"sprzet_id", "nazwa", "koszt"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][3];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("sprzet_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("nazwa");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("koszt");
                            }while(TrenerzyRs.next());

                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Piłkarze") :
                        Border pilkarzBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "Piłkarz");
                        tabelaScrollPane.setBorder(pilkarzBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from pilkarz",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"pilkarz_id", "imie", "nazwisko","pozycja"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][4];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("pilkarz_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("imie");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("nazwisko");
                                data[TrenerzyRs.getRow()-1][3] = TrenerzyRs.getString("pozycja");

                            }while(TrenerzyRs.next());

                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Treningi"):
                        Border treningBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "Trening");
                        tabelaScrollPane.setBorder(treningBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from trening",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"trening_id", "dzien_treningu", "trener_id","sala_id","sprzet_id"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][5];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("trening_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("dzien_treningu");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("trener_id");
                                data[TrenerzyRs.getRow()-1][3] = TrenerzyRs.getString("sala_id");
                                data[TrenerzyRs.getRow()-1][4] = TrenerzyRs.getString("sprzet_id");

                            }while(TrenerzyRs.next());

                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Treningi piłkarzy"):
                        Border treningPBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "trening_pilkarz");
                        tabelaScrollPane.setBorder(treningPBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from trening_pilkarz",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"trening_pilkarz_id", "trening_id","pilkarz_id"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][3];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("trening_pilkarz_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("trening_id");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("pilkarz_id");
                            }while(TrenerzyRs.next());

                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    case("Ćwiczenia fizjoterapeutyczne"):
                        Border cwiczeniaBorderE = BorderFactory.createTitledBorder(trenerzyBorder, "cwiczenia_fizjoterapeuta");
                        tabelaScrollPane.setBorder(cwiczeniaBorderE);

                        try{
                            PreparedStatement Trenerzy = connection.prepareStatement("SELECT * from cwiczenia_fizjoterapeuta",ResultSet.TYPE_SCROLL_INSENSITIVE,
                                    ResultSet.CONCUR_READ_ONLY);
                            ResultSet TrenerzyRs = Trenerzy.executeQuery();

                            String [] columnNames = {"cwiczenia_fizjoterapeuta_id", "fizjoterapeuta_id","pilkarz_id","dzien_cwiczen"};
                            TrenerzyRs.last();
                            String [][] data = new String[TrenerzyRs.getRow()][4];
                            TrenerzyRs.first();
                            do {
                                data[TrenerzyRs.getRow()-1][0] = TrenerzyRs.getString("cwiczenia_fizjoterapeuta_id");
                                data[TrenerzyRs.getRow()-1][1] = TrenerzyRs.getString("fizjoterapeuta_id");
                                data[TrenerzyRs.getRow()-1][2] = TrenerzyRs.getString("pilkarz_id");
                                data[TrenerzyRs.getRow()-1][3] = TrenerzyRs.getString("dzien_cwiczen");
                            }while(TrenerzyRs.next());

                            JTable specificReviewsTable = new JTable(data, columnNames);
                            tabelaScrollPane.setViewportView(specificReviewsTable);

                        }catch (SQLException ex){throw new RuntimeException(ex);}
                        break;
                    default:
                        break;
                }
                base.closeConnection(connection);
            }
        });



    }

}
