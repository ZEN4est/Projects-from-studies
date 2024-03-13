package gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DodajAdmin extends JFrame{
    private JPanel panel1;
    private JButton pilkarzButton;
    private JButton trenerButton;
    private JButton fizjoterapeutaButton;
    private JButton salaButton;
    private JButton sprzetButton;
    private JButton treningButton;
    private JButton przypiszPilkarzaButton;
    private JButton cwiczeniaFizjoterapeutyczneButton;
    private JButton powrotButton;

    public DodajAdmin(){
        setContentPane(panel1);
        setTitle("Dodaj Admin");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        powrotButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Admin();
                dispose();
            }
        });

        pilkarzButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajPilkarza();
                dispose();
            }
        });

        trenerButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajTrenera();
                dispose();
            }
        });

        fizjoterapeutaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajFizjoterapeute();
                dispose();
            }
        });

        salaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajSale();
                dispose();
            }
        });

        sprzetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajSprzet();
                dispose();
            }
        });

        treningButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajTrening();
                dispose();
            }
        });

        przypiszPilkarzaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajPilkarzaDoTreningu();
                dispose();
            }
        });

        cwiczeniaFizjoterapeutyczneButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new DodajCwiczeniaFizjoterapeuta();
                dispose();
            }
        });
    }
}
