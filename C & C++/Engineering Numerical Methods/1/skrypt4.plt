set multiplot layout 2,1


set xlabel "t"
set ylabel "Q(t)"
set xrange[0.0:0.3]
set yrange[-0.003:0.0035]
set title "z.4 - Metoda RK4, Q(t)" 
plot "zad4aQ.dat" with lines lc rgb "green" lw 2 title "w0=0.5",\
"zad4bQ.dat" with lines lc rgb "blue" lw 2 title "w0=0.8",\
"zad4cQ.dat" with lines lc rgb "red" lw 2 title "w0=1.0",\
"zad4dQ.dat" with lines lc rgb "orange" lw 2 title "w0=1.2",\

set xlabel "t"
set ylabel "I(t)"
set xrange[0.0:0.3]
set yrange[-0.12:0.12]
set title "z.4 - Metoda RK4, I(t)"
plot "zad4aI.dat" with lines lc rgb "green" lw 2 title "w0=0.5",\
"zad4bI.dat" with lines lc rgb "blue" lw 2  title "w0=0.8",\
"zad4cI.dat" with lines lc rgb "red" lw 2 title "w0=1.0",\
"zad4dI.dat" with lines lc rgb "orange" lw 2 title "w0=1.2",

unset multiplot