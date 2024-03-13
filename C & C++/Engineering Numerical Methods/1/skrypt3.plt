set multiplot layout 2,1

set xlabel "t"
set ylabel "y(t)"
set xrange[0.0:5.0]
set yrange[0.0:1.0]
set title "z.3 - Metoda RK4 - rozwiazanie" 
plot "zad3a.dat" with points pointtype 7 title "dt=0.01",\
"zad3b.dat" with points pointtype 7 title "dt=0.1",\
"zad3c.dat" with points pointtype 7 title "dt=1.0",\

set xlabel "t"
set ylabel "ynum(t) - ydok(t)"
set xrange[0.0:5.0]
set yrange[-0.001:0.008]
set title "z.3 - Metoda RK4 - blad"
plot "zad3aBlad.dat" with lines lw 2 title "dt=0.01",\
"zad3bBlad.dat" with lines lw 2 title "dt=0.1",\
"zad3cBlad.dat" with lines lw 2 title "dt=1.0",

unset multiplot