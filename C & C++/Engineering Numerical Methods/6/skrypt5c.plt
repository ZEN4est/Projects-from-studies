reset
set term png
set out "5c.png"

set pm3d interpolate 0,0

set view map
set palette defined (-1 "blue", 0 "white", 1 "red")
set size ratio 1
set xrange[0:20]
set yrange[0:20]
set title 'nx=ny=200'
set xlabel 'x'
set ylabel 'y'
set key off

plot "5c.dat" with image
reset