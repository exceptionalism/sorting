## Sorting

Complexity analysis on sorting random integers.

## Requirements and Dependencies:

* [GNU c/c++ compiler]
  > sudo apt install gcc

* [Python2.7 and dependencies]
  > sudo apt install python2.7
  
* [NumPy]
  > python2.7 -m pip install numpy
  
* [Matplotlib]
  > python2.7 -m pip install matplotlib

* [matplotlib-cpp] (Already Included)
    https://github.com/lava/matplotlib-cpp


## Usage:

1.  Compilation:
   > g++ main.cpp -std=c++14 -I/usr/include/python2.7 -lpython2.7

2.  Execution:
  > ./a.out 9000

Command-line arguements:
    
  * argv[1]   : Max No. of elements to be sorted       


## Analysis:

* Analysis on 9K Elements:

![Sorting_9K](https://github.com/exceptionalism/sorting/blob/master/plot_9K.png)

* Analysis on 1M Elements:

![Sorting_1M](https://github.com/exceptionalism/sorting/blob/master/plot_1M.png)
