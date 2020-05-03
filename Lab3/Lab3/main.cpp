#include <iostream>

#include "CycledChain.h"
#include "ArrayList.h"
#include "circularListWithHeader.h"
#include "hashTable.h"
#include <map>

const int AMOUNT = 10;
const int POPULATION_SIZE = 32;
const int MATRIX_SIZE = 10;

/*
TODO :
1. implement cycled chain and array list
2. implement monkey election
*/

int main(int argc, char const* argv[])
{
    // TASK 1. Monkey election.
    int x = 1337;

    // ArrayList approach. Here operator % is being used to calculate indexes.
    // Current element index is being cycled by modulo SIZE.

    ArrayList<int> *list = new ArrayList<int>();

    // Generate monkeys.
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        list->insert(i, i);
    }

    // Set p number.
    int p = 16;
    int index;

    // Perform election.
    while (list->size() > 1)
    {
        index = p - 1;
        index %= list->size();
        list->erase(index);
    }

    cout << list->get(0) << endl;

    delete list;


    // CycledChain approach. Here chain is cycled by itself.
    // All we need is just iterate over chain till SIZE = 1.

    circularListWithHeader<int>* chain = new circularListWithHeader<int>();

    for (int i = 0; i < 3; i++)
    {
        chain->insert(i, i);
    }

    circularListWithHeader<int>::Iterator iterator = chain->begin();

    for (circularListWithHeader<int>::Iterator it = chain->begin(); it != chain->head(); it++)
    {
        cout << *it << endl;
    }

    //do
    //{
    //    // Make p steps.
    //    for (int i = 0; i < p - 1; i++) iterator++;
    //    // save value.
    //    x = *iterator;
    //    // TODO : continue from here.
    //} while (chain->size() != 0);

    delete chain;

    // TASK 2. Matrix.

    // Create and generate values
    int** matrix;
    matrix = new int* [MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        matrix[i] = new int[MATRIX_SIZE];
        for (int j = 0; j < MATRIX_SIZE; j++)
            matrix[i][j] = (int)rand() % 10;
    }

    // Use STL map container to store frequencies
    std::map<int, int> freq;

    // 1. Store all frequencies
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (freq[matrix[i][j]])
                freq[matrix[i][j]] += 1;
            else
                freq[matrix[i][j]] = 1;
        }
    }

    // 2. Make frequencies table
    int** ind = new int* [freq.size()];
    int ii = 0;
    for (auto it = freq.begin(); it != freq.end() && ii < freq.size(); it++, ii++)
    {
        ind[ii] = new int[3] { it->first, it->second, ii };
    }

    // 3. Reconstruct matrix
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            matrix[i][j] = freq[matrix[i][j]];

    return 0;
}
