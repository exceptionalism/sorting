#include <iostream>
#include <vector>
#include "algorithms.cpp"

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

using namespace std;
using namespace std::chrono;

// Array of Functions
typedef void (*ArrayOfSorts)(vector<int> &ar);
ArrayOfSorts sorts[] = {bubble_sort, selection_sort, insertion_sort, quick_sort, merge_sort, heap_sort};
string sortNames[] = {"bubble_sort", "selection_sort", "insertion_sort", "quick_sort", "merge_sort", "heap_sort"};

// Generates 'num' number of linearly spaced integers ranging from 'start' to 'end'
vector<int> linspace(int start, int end, int num)
{
    vector<int> linspaced;

    if (num == 0)
        return linspaced;

    else if (num == 1)
    {
        linspaced.push_back(start);
        return linspaced;
    }

    int delta = (end - start) / (num - 1);

    for (int i = 0; i < num - 1; ++i)
        linspaced.push_back(start + delta * i);

    linspaced.push_back(end);
    return linspaced;
}

// Wrapper for Variables that are needed for plots (N vs Time)
struct plotVariables
{
    vector<int> N;
    vector<int> Time;
} Graph;

// Input for max number of elements to be sorted
void input(int N = -1)
{
    if (N == -1)
    {
        cout << "Enter max no. of elements to be sorted: " << endl;
        cin >> N;
    }

    Graph.N = linspace(0, N, 30);
}

// Plots graph based on 'plotVariables' and 'Sort' function below
void Plot(int sortIndex, bool savePdf = false)
{
    plt::named_plot(sortNames[sortIndex], Graph.N, Graph.Time);
    plt::title("N vs. Time Graph");
    plt::legend();

    plt::xlabel("No. of elements");
    plt::ylabel("Time in milliseconds");

    if (savePdf)
        plt::save("plot.pdf");
}

// Takes index of a sort and plots graph for N elements of that single sort
void Sort(int sortIndex, bool plot = false, bool savePdf = false)
{
    vector<int>::iterator NoOfElements;
    Graph.Time.clear();

    for (NoOfElements = (Graph.N).begin(); NoOfElements < (Graph.N).end(); NoOfElements++)
    {
        vector<int> arr(*NoOfElements);
        generate(arr.begin(), arr.end(), std::rand);

        auto start = high_resolution_clock::now();
        sorts[sortIndex](arr);
        auto stop = high_resolution_clock::now();

        int Duration = int(duration_cast<milliseconds>(stop - start).count());

        cout << sortNames[sortIndex] << " Elements: " << *NoOfElements << "\n\tTime: " << Duration << " ms" << endl;
        (Graph.Time).push_back(Duration);

        if (plot)
            Plot(sortIndex, savePdf);

        // if(Duration >= 13000)
        //     break;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        input(std::stoi(argv[1]));
    else
        input();

    int numSorts = sizeof(sortNames) / sizeof(sortNames[0]);
    for (int sortIndex = 0; sortIndex < numSorts; sortIndex++)
        Sort(sortIndex, true); // plot = true

    plt::show();
    return 0;
}

/*

Compiled with: 
-------------------------
g++ main.cpp -std=c++14 \
-I /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 \
-I /System/Library/Frameworks/Python.framework/Versions/2.7/Extras/lib/python/numpy/core/include \
-L /System/Library/Frameworks/Python.framework/Versions/2.7/Extras/lib/python \
-lpython2.7

./a.out 9000

*/