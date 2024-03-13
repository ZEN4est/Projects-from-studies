set term png
set out "it2000.png"

set multiplot layout 2,2

set pm3d interpolate 0,0

set view map


set xrange[0:40]
set yrange[0:40]
set title "it=2000"
set xlabel "x"
set ylabel "y"
set key off

plot "T1_2000.dat" with image

set view map


set xrange[0:40]
set yrange[0:40]
set title "it=2000"
set xlabel "x"
set ylabel "y"
set key off

plot "T2_2000.dat" with image


unset view
unset multiplot