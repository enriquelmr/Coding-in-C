set terminal png
set output "A.png"
set xlabel "r"
set ylabel "A"
set grid
set zeroaxis
set border lw 2

plot "datos.dat" lc "red" title ""
