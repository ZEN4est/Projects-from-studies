set term png
set out "S(it).png"


set ylabel "S"
set xlabel "it"
set xrange[0:600]
set yrange[4.2:5.6]
set title "S(it)" 
plot "wartosc1.dat" with lines lw 2 title "k=1",\
"wartosc2.dat" with lines lw 2 title "k=2",\
"wartosc4.dat" with lines lw 2 title "k=4",\
"wartosc8.dat" with lines lw 2 title "k=8",\
"wartosc16.dat" with lines lw 2 title "k=16",