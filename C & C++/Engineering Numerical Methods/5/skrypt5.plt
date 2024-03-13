set term png
set out "k16.png"

set pm3d interpolate 0,0

set xrange[0:25]
set yrange[0:25]
set title "k=1"
set xlabel "x"
set ylabel "y"
set key off

plot "k16.dat" with image


