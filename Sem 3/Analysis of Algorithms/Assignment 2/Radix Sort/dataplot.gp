set terminal png size 800,600
set output 'radix_sort.png'
set title "Radix Sort Time Complexity"
set xlabel "Array Size"
set ylabel "Time (seconds)"
set grid
plot "data.txt" using 1:2 with linespoints title "Best Case" lt rgb 'green', \
     "data.txt" using 1:3 with linespoints title "Worst Case" lt rgb 'red', \
     "data.txt" using 1:4 with linespoints title "Average Case" lt rgb 'blue'