set term png
set out "k2.png"

set pm3d interpolate 0,0

set xrange[0:25]
set yrange[0:25]
set title "k=2"
set xlabel "x"
set ylabel "y"
set key off

plot "k2.dat" with image


