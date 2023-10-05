set terminal png
set output "grafica_potencial.png"
set xlabel "x"
set ylabel "y"
set grid
set zeroaxis
set border lw 2
plot "datos_potencial.dat" lc "red" title ""
