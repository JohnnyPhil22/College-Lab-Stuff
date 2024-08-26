set terminal png size 800, 600
set output 'avg_ins_bub_sort.png'
set title "Average Time Complexity for Insertion and Bubble Sort"
set xlabel "Array Size"
set ylabel "Time (seconds)"
set grid
plot "insData.txt" with linespoints title "Insertion Sort", "bubData.txt" with linespoints title "Bubble Sort"
