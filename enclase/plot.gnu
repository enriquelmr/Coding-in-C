set terminal gif animate delay 1
set encoding utf8
set termoption enhanced
set output 'UpWind.gif'
stats 'datos.dat' using 2 name 'A' nooutput
set xrange [-10.000000:10.000000]
set yrange [A_min:A_max]
set xlabel "x"
set ylabel 'Φ' 
set title "UpWind" 
set grid 
set zeroaxis 
set border lw 2 
do for [i=0:50]{plot 'datos.dat' index i lc 'red notitle'}
