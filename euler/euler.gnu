set terminal png 
set output "grafica_euler.png"
set xlabel "x"
set ylabel "y"
set grid
set zeroaxis
set border lw 2
plot "datos_euler.dat" lc "black" title "",[0:4] x*x lc "blue" title "",[4:10] x*x lc "green" title ""