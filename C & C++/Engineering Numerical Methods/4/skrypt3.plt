set term png
set out "lokalna.png"

set logscale x 10
set ylabel "S"
set xlabel "nr iteracji"
set xrange[1:100000]
set yrange[0:3000]
set title "Relaksacja lokalna" 
plot "lokalna.dat" with lines lw 2 title "w=1.0, 12194 it",\
"lokalna2.dat" with lines lw 2 title "w=1.4, 5548 it", \
"lokalna3.dat" with lines lw 2 title "w=1.8, 1553 it",\
"lokalna4.dat" with lines lw 2 title "w=1.9, 751 it",
