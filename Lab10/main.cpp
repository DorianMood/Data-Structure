#include <iostream>
#include <stdlib.h>
#include "WinnerTree.h"
#include "WinNode.h"


int winner(WinNode a[], int b, int c)
{// For a min winner tree.
	if (a[b].key <= a[c].key) return b;
	return c;
}


//int main()
//{
//    WinnerTree<WinNode> W(20);
//    WinNode element[20];
//    int n;
//    std::cout << "Enter number of players, between 8 and 20" << std::endl;
//    std::cin >> n;
//    if (n < 8 || n > 20)
//    {
//        std::cout << "Bad input" << std::endl;
//        exit(1);
//    }
//    std::cout << "Enter player values" << std::endl;
//
//    for (int i = 1; i <= n; i++)
//        std::cin >> element[i].key;
//
//    W.Initialize(element, n, winner);
//    std::cout << "The winner tree is" << std::endl;
//    W.Output();
//
//    element[2].key = 0;
//    W.RePlay(2, winner);
//    std::cout << "Changed player 2 to zero, new tree is" << std::endl;
//    W.Output();
//
//    element[3].key = -1;
//    W.RePlay(3, winner);
//    std::cout << "Changed player 3 to -1, new tree is" << std::endl;
//    W.Output();
//
//    element[7].key = 2;
//    W.RePlay(7, winner);
//    std::cout << "Changed player 7 to 2, new tree is" << std::endl;
//    W.Output();
//
//	return 0;
//}