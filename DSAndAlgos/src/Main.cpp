
#include "SpiralPrint.h"
#include <iostream>

int main()
{
    int arr[row][col] = { 
    { 15, 58, 7, 12, 18 },
    { 8, 10, 53, 6, 22 },
    { 4, 21, 45, 70, 27 },
    { 90, 1, 34, 76, 11 },
    { 2, 80, 89, 23, 41 }
    };

    printSpiral(arr, row, col);
    std::cout << std::endl;
    printSpiralRecursive(arr, 0, row, 0, col);
    std::cin.get();
}