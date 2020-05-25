#include <iostream>
#include <algorithm>

#include "binarySearchTreeWithVisit.h"
#include "BST.h"

const int N = 10;

int main()
{
    binarySearchTree<int, int>* tree = new binarySearchTree<int, int>();

    tree->insert(std::make_pair<int, int>(1, 2));
    tree->insert(std::make_pair<int, int>(2, 2));
    tree->insert(std::make_pair<int, int>(3, 2));

    tree->inOrderOutput();

    /*
    Write a histogramming program that first inputs the n keys into an array,
    then sorts this array, and finally makes a left-to-right scan of the array
    outputting the distinct key values and the number of times each occurs.
    */

    int* arr = new int[N];

    // Input N keys into array
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    // Sort this array
    sort(arr, arr + N);

    // Left-to-righ scan of the array
    for (int i = 0; i < N; i++)
    {

    }

    return 0;
}
