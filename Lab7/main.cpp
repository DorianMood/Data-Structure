#include <iostream>

#include "SortedList.h"

int main()
{
    /**
    Develop the C++ class SortedList  that uses a formula-based representation .
    Provide the same member functions as provided the class SortedChain .
    Write code for all functions and test the code using suitable test data.
    */

    SortedList<int, int>* list = new SortedList<int, int>();

    // Test Intertion.

    list->Insert(std::make_pair(2, 1));
    list->Insert(std::make_pair(3, 1));
    list->Insert(std::make_pair(1, 1));
    list->Insert(std::make_pair(4, 1));

    list->Output(std::cout);

    // Test Erase.

    list->Erase(3);
    list->Erase(4);
    list->Erase(1);
    list->Erase(1);

    list->Output(std::cout);
    
    //  Test Insert again.

    list->Insert(std::make_pair(5, 12));
    list->Insert(std::make_pair(0, -12));

    list->Output(std::cout);

    return 0;
}
