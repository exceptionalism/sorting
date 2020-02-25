# Sorting

Complexity analysis of sorting random integers

## Requirements and Dependencies

* [GNU c/c++ compiler and dependencies]
  > sudo apt install gcc

* [Python2.7 and dependencies]
  > sudo apt install python2.7
  > python2.7 -m pip install numpy
  > python2.7 -m pip install matplotlib

* [matplotlib-cpp] (Already Included)
    https://github.com/lava/matplotlib-cpp

## Usage

1. Compilation:

   > g++ main.cpp -std=c++14 -I/usr/include/python2.7 -lpython2.7

2. Execution:

  > ./a.out 9000

    Command-line arguements:
    
      * argv[1]   : Max No. of elements to be sorted       

## Analysis

* Analysis on 9K Random Integers:

![Sorting_9K](https://github.com/exceptionalism/sorting/blob/master/outputs/plot_9K_random.png)

* Analysis on 1M Random Integers:

![Sorting_1M](https://github.com/exceptionalism/sorting/blob/master/outputs/plot_1M_random.png)

* Analysis on 1M Random Integers:

![Sorting_1M](https://github.com/exceptionalism/sorting/blob/master/outputs/plot_1M_random.png)

* Bubble Sort:

![bubbleSort](https://github.com/exceptionalism/sorting/blob/master/outputs/bubbleSort.png)

* Selection Sort:

![selectionSort](https://github.com/exceptionalism/sorting/blob/master/outputs/selectionSort.png)

* Insertion Sort:

![insertionSort](https://github.com/exceptionalism/sorting/blob/master/outputs/insertionSort.png)

* Merge Sort:

![mergeSort](https://github.com/exceptionalism/sorting/blob/master/outputs/mergeSort.png)

* Heap Sort:

![heapSort](https://github.com/exceptionalism/sorting/blob/master/outputs/heapSort.png)

* Quick Sort:

![quickSort](https://github.com/exceptionalism/sorting/blob/master/outputs/quickSort.png)
