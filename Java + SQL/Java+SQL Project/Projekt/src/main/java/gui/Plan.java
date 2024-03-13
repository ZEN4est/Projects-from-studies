package gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Plan extends JFrame{
    private JButton planOgolnyButton;
    private JButton planOsobyButton;
    private JLabel plan;
    private JPanel panelButtons;
    private JPanel panel1;
    private JButton powrotButton;

    public Plan(){
        setContentPane(panel1);
        setTitle("Plan");
        setSize(600, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        powrotButton.addActionListener(new ActionListener() {
        @Override
            public void actionPerformed(ActionEvent e) {
                new StronaStartowa();
                dispose();
            }
        });

        planOsobyButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new PlanOsoby();
                dispose();
            }
        });

        planOgolnyButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new PlanOgolny();
                dispose();
            }
        });

    }
}
