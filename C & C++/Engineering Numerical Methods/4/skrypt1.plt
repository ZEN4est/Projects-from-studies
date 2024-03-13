set term png
set out "GlobalnaBlad.png"

set multiplot layout 2,1

set view map 

set xrange[0:15]
set yrange[0:10]
set title "Blad relaksacji globalnej w=0.6"
set xlabel "Latitude (b)[degrees]"
set ylabel "Longitude (l)[degrees]"
set key off

splot "globalnaBlad1.dat" with points palette pt 9 


set view map 

set xrange[0:15]
set yrange[0:10]
set title "Blad relaksacji globalnej w=1.0"
set xlabel "Latitude (b)[degrees]"
set ylabel "Longitude (l)[degrees]"
set key off

splot "globalnaBlad2.dat" with points palette pt 9 


unset view
unset multiplot