set terminal png
set output "B.png"
set xlabel "r"
set ylabel "B"
set grid
set zeroaxis
set border lw 2

plot "datosb.dat" lc "red" title ""
