set terminal png 
set output "grafica_runge.png"
set xlabel "x"
set ylabel "y"
set grid
set zeroaxis
set border lw 2
plot "datos_runge.dat" lc "black" title "", sin(x) lc "blue" title ""
