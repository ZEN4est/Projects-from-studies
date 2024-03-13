reset
set term png
set out "6c.png"

set pm3d interpolate 0,0

set view map
set palette defined (-1 "blue", 0 "white", 1 "red")
set size ratio 1
set xrange[0:10]
set yrange[0:10]
set cbrange [-0.8:0.8]
set title 'E1=1, E2=10'
set xlabel 'x'
set ylabel 'y'
set key off

plot "6c.dat" with image
reset