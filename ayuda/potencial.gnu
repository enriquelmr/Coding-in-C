set terminal png 
set output "grafica_potencial.png"
set xlabel "x"
set ylabel "y"
set grid
set zeroaxis
set border lw 2
plot "datos_potencial.dat" lc "red" title "",[0:1] 0.666*pi*x*x lc "blue" title "",[1:10] 0.666*pi*(1/x) lc "blue" title ""
