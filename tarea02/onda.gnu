set terminal gif animate delay 1
set termoption enhanced
set output 'laonda.gif'
stats 'datos.dat' using 2 name 'A' nooutput
set xrange [-7.0000000000:7.00000000000]
set yrange [A_min:A_max]
set xlabel "x"
set ylabel "exp(-x^2)"
set grid
set zeroaxis
set border lw 2

do for [i=0:100]{plot 'datos.dat' index i lc 'black notitle'}
