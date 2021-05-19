reset
set terminal png
set output 'measurement.png'
set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [s]"
set key top left

plot "quicksort.txt" with linespoints title "QuickSort" ,\
     "mergesort.txt" with linespoints title "Mergesort" ,\
     "heapsort.txt" with linespoints title "Heapsort"   ,\
     "shellsort.txt" with linespoints title "Shellsort" ,\