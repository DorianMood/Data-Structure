#include <iostream>
#include <algorithm>
#include <map>

//#include "binarySearchTreeWithVisit.h"
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

    std::map<int, int> frequencies;

    // Left-to-righ scan of the array
    for (int i = 0; i < N; i++)
    {
        if (frequencies.find(arr[i]) == frequencies.end())
            frequencies.insert(std::make_pair(arr[i], 0));
        frequencies[arr[i]]++;
    }

    for (auto element : frequencies)
    {
        std::cout << element.first << ":" << element.second << " ; ";
    }
    std::cout << std::endl;

    return 0;
}
