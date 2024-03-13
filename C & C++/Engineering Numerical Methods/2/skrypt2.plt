set term png
set out "newton.png"
set xlabel "t"
set ylabel "u(t),v(t)"
set xrange[0.0:100.0]
set yrange[0.0:600.0]
set title "Metoda Newtona" 
plot "zad1newtonu.dat" with lines lw 2 title "u(t)",\
"zad1newtonz.dat" with lines lw 2 title "z(t)",
