set multiplot layout 2,1

set xlabel "t"
set ylabel "y(t)"
set xrange[0.0:5.0]
set yrange[0.0:1.0]
set title "z.2 - Metoda RK2 - rozwiazanie" 
plot "zad2a.dat" with points pointtype 7 title "dt=0.01",\
"zad2b.dat" with points pointtype 7 title "dt=0.1",\
"zad2c.dat" with points pointtype 7 title "dt=1.0",\

set xlabel "t"
set ylabel "ynum(t) - ydok(t)"
set xrange[0.0:5.0]
set yrange[-0.02:0.15]
set title "z.2 - Metoda RK2 - blad"
plot "zad2aBlad.dat" with lines lw 2 title "dt=0.01",\
"zad2bBlad.dat" with lines lw 2 title "dt=0.1",\
"zad2cBlad.dat" with lines lw 2 title "dt=1.0",

unset multiplot