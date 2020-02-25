#include <iostream>
using namespace std;

// Generate ordered elements (best case)
int ordered()
{
    static int i = 1;
    return i++;
}

// Generate reversely ordered elements (best case)
int reverseOrdered()
{
    static int i = 1000000;
    return i--;
}