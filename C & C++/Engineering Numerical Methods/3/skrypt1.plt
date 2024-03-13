set term png
set out "trapez.png"

set multiplot layout 2,2

set xlabel "t"
set xrange[0.0:45.0]
set yrange[-2.5:2.5]
set title "v(t)" 
plot "trapezvt.dat" with lines lw 2 title "tol=10^-2",\
"trapezvt2.dat" with lines lw 2 title "tol=10^-5",

set xlabel "t"
set xrange[0.0:45.0]
set yrange[-2.5:2.5]
set title "x(t)" 
plot "trapezxt.dat" with lines lw 2 title "tol=10^-2",\
"trapezxt2.dat" with lines lw 2 title "tol=10^-5",

set xlabel "t"
set xrange[0.0:45.0]
set yrange[0.0:1.0]
set title "dt(t)" 
plot "trapezdtt.dat" with lines lw 2 title "tol=10^-2",\
"trapezdtt2.dat" with lines lw 2 title "tol=10^-5",

set xlabel "t"
set xrange[-2.5:2.5]
set yrange[-8:8]
set title "v(x)" 
plot "trapezvx.dat" with lines lw 2 title "tol=10^-2",\
"trapezvx2.dat" with lines lw 2 title "tol=10^-5",


unset multiplot