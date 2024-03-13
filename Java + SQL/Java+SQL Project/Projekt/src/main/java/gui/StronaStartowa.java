package gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StronaStartowa extends JFrame{
    private JPanel panel;
    private JButton budzetButton;
    private JButton planButton;
    private JButton wyswietlDaneButton;
    private JButton adminPanelButton;

    public StronaStartowa(){
        setContentPane(panel);
        setTitle("Strona startowa");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        budzetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Budzet();
                dispose();
            }
        });
        planButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Plan();
                dispose();
            }
        });
        wyswietlDaneButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new WyswietlDane();
                dispose();
            }
        });
        adminPanelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Admin();
                dispose();
            }
        });
    }

}

