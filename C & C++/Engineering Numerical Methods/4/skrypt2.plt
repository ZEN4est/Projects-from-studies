set term png
set out "globalna.png"

set logscale x 10
set ylabel "S"
set xlabel "nr iteracji"
set xrange[1:100000]
set yrange[0:5000]
set title "Relaksacja globalna" 
plot "globalna1.dat" with lines lw 2 title "w=0.6, 36887 it",\
"globalna2.dat" with lines lw 2 title "w=1.0, 23097 it",
