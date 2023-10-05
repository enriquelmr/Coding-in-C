set terminal png 
set output "grafica_potencial.png"
set xlabel "r"
set ylabel "Potencial"
set grid
set zeroaxis
set border lw 2
set yrange [0:2]
plot "datos_potencialexp.dat" lc "red" title ""