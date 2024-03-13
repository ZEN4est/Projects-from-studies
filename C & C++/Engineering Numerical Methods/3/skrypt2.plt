set term png
set out "RK2.png"

set multiplot layout 2,2

set xlabel "t"
set xrange[0.0:45.0]
set yrange[-2.5:2.5]
set title "v(t)" 
plot "RK2vt.dat" with lines lw 1 title "tol=10^-2",\
"RK2vt2.dat" with lines lw 1 title "tol=10^-5",

set xlabel "t"
set xrange[0.0:45.0]
set yrange[-2.5:2.5]
set title "x(t)" 
plot "RK2xt.dat" with lines lw 1 title "tol=10^-2",\
"RK2xt2.dat" with lines lw 1 title "tol=10^-5",

set xlabel "t"
set xrange[0.0:45.0]
set yrange[0.0:1.0]
set title "dt(t)" 
plot "RK2dt.dat" with lines lw 1 title "tol=10^-2",\
"RK2dt2.dat" with lines lw 1 title "tol=10^-5",

set xlabel "t"
set xrange[-2.5:2.5]
set yrange[-8:8]
set title "v(x)" 
plot "RK2vx.dat" with lines lw 1 title "tol=10^-2",\
"RK2vx2.dat" with lines lw 1 title "tol=10^-5",


unset multiplot