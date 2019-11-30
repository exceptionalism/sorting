#include <iostream>
#include <vector>

using namespace std;

#define _swap(a, b) \
    {               \
        int temp;   \
        temp = a;   \
        a = b;      \
        b = temp;   \
    }

void print(vector<int> const &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr.at(i) << ' ';
    }
    cout << endl;
}

void bubble_sort(std::vector<int> &arr)
{
    int length = arr.size();

    for (int i = 0; (i < length); i++)
    {
        for (int j = 0; j < length - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
                _swap(arr[j], arr[j + 1]);
        }
    }
    return;
}

void selection_sort(std::vector<int> &arr)
{
    int length = arr.size();

    for (int i = 0; i < length; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        _swap(arr[i], arr[min]);
    }
    return;
}

void insertion_sort(std::vector<int> &arr)
{
    int length = arr.size();
    int key, backwardIndex;
    for (int forwardIndex = 1; forwardIndex < length; forwardIndex++)
    {
        key = arr[forwardIndex];      //take value
        backwardIndex = forwardIndex; // backwardIndex checks for key's position in backward direction
        while (backwardIndex > 0 && arr[backwardIndex - 1] > key)
        {
            arr[backwardIndex] = arr[backwardIndex - 1];
            backwardIndex--;
        }
        arr[backwardIndex] = key; //insert in right place
    }
}

int partition(vector<int> &values, int leftIndex, int rightIndex)
{
    int pivotIndex = leftIndex + (rightIndex - leftIndex) / 2;
    int pivotValue = values[pivotIndex];
    int temp;
    while (leftIndex <= rightIndex)
    {
        while (values[leftIndex] < pivotValue)
            leftIndex++;
        while (values[rightIndex] > pivotValue)
            rightIndex--;

        if (leftIndex <= rightIndex)
        {
            temp = values[leftIndex];
            values[leftIndex] = values[rightIndex];
            values[rightIndex] = temp;
            leftIndex++;
            rightIndex--;
        }
    }
    return leftIndex;
}
void _quick_sort(std::vector<int> &arr, int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int pivotIndex = partition(arr, leftIndex, rightIndex);

        _quick_sort(arr, leftIndex, pivotIndex - 1);
        _quick_sort(arr, pivotIndex + 1, rightIndex);
    }
}

void quick_sort(std::vector<int> &arr)
{
    _quick_sort(arr, 0, arr.size() - 1);
}

void _merge(vector<int>::iterator begin, vector<int>::iterator middle, vector<int>::iterator end)
{
    size_t distance = end - begin; // distance = std::distance(begin, end)
    std::vector<int> aux(distance);

    vector<int>::iterator left = begin;
    vector<int>::iterator left_bound = middle;
    vector<int>::iterator right = middle;
    vector<int>::iterator right_bound = end;
    size_t aux_index = 0;

    while (left != left_bound && right != right_bound)
    {
        if (*right < *left)
        {
            aux[aux_index++] = *right;
            right++;
        }
        else
        {
            aux[aux_index++] = *left;
            left++;
        }
    }

    copy(left, left_bound, &aux[aux_index]);
    copy(right, right_bound, &aux[aux_index]);
    copy(aux.begin(), aux.end(), begin);
}

void _merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    size_t distance = end - begin; // distance = std::distance(begin, end)

    if (distance < 2)
        return;

    vector<int>::iterator middle = begin;
    advance(middle, distance / 2);

    _merge_sort(begin, middle);
    _merge_sort(middle, end);
    _merge(begin, middle, end);
}

void merge_sort(vector<int> &arr)
{
    _merge_sort(arr.begin(), arr.end());
}

void heapify(std::vector<int> &arr, int length, int middleIndex)
{
    int largestIndex = middleIndex;       // Initialize largest as root
    int leftIndex = 2 * middleIndex + 1;  // 1st loop: 2nd last element, 2nd loop: 3rd last element ...
    int rightIndex = 2 * middleIndex + 2; // 1st loop: last element, 2nd loop: 2nd last element ...

    if (leftIndex < length && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;

    if (rightIndex < length && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;

    if (largestIndex != middleIndex)
    {
        swap(arr[middleIndex], arr[largestIndex]);
        // Recursively heapify for every child
        heapify(arr, length, largestIndex);
    }
}

void heap_sort(std::vector<int> &arr)
{
    int length = arr.size();

    // Build heap (rearrange array)
    for (int middleIndex = length / 2 - 1; middleIndex >= 0; middleIndex--)
        heapify(arr, length, middleIndex);

    // One by one extract an element from heap
    for (int i = length - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}