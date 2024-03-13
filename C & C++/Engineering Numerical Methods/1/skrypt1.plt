set multiplot layout 2,1

set xlabel "t"
set ylabel "y(t)"
set xrange[-0.1:5.0]
set yrange[-0.01:1.0]
set title "z.1 - Metoda Eulera - rozwiazanie" 
plot "zad1a.dat" with points pointtype 7 title "dt=0.01",\
"zad1b.dat" with points pointtype 7 title "dt=0.1",\
"zad1c.dat" with points pointtype 7 title "dt=1.0",\
exp(-x) title "exp(-x)"

set xlabel "t"
set ylabel "ynum(t) - ydok(t)"
set xrange[-0.1:5.0]
set yrange[-0.4:0.01]
set title "z.1 - Metoda Eulera - blad"
plot "zad1aBlad.dat" with lines lw 2 title "dt=0.01",\
"zad1bBlad.dat" with lines lw 2 title "dt=0.1",\
"zad1cBlad.dat" with lines lw 2 title "dt=1.0",

unset multiplot