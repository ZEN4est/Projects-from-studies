set term png
set out "RK2.png"
set xlabel "t"
set ylabel "u(t),v(t)"
set xrange[0.0:100.0]
set yrange[0.0:600.0]
set title "Niejawna RK2" 
plot "zad2u.dat" with lines lw 2 title "u(t)",\
"zad2z.dat" with lines lw 2 title "z(t)",
