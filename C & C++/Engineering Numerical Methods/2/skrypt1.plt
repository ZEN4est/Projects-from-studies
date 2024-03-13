set term png
set out "picard.png"
set xlabel "t"
set ylabel "u(t),v(t)"
set xrange[0.0:100.0]
set yrange[0.0:600.0]
set title "Metoda Picarda" 
plot "zad1picardu.dat" with lines lw 2 title "u(t)",\
"zad1picardz.dat" with lines lw 2 title "z(t)",


