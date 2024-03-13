set term png
set out "it100.png"

set multiplot layout 2,2

set pm3d interpolate 0,0

set view map

set xrange[0:40]
set yrange[0:40]
set title "it=100"
set xlabel "x"
set ylabel "y"
set key off


plot "T1_100.dat" with image

set view map

set xrange[0:40]
set yrange[0:40]
set title "it=100"
set xlabel "x"
set ylabel "y"
set key off

plot "T2_100.dat" with image

unset view
unset multiplot