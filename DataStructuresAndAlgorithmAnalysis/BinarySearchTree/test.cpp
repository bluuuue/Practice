#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST TempTree;
    TempTree.InsertValue(16);
    TempTree.InsertValue(18);
    TempTree.InsertValue(8);
    TempTree.InsertValue(12);
    TempTree.InsertValue(11);
    TempTree.InsertValue(14);
    TempTree.InsertValue(9);
    TempTree.InsertValue(10);
    TempTree.InsertValue(4);
    TempTree.InsertValue(2);
    TempTree.InsertValue(6);
    TempTree.InsertValue(5);
    TempTree.FindValue(4);
    TempTree.FindValue(7);
    TempTree.FindMaxValue();
    TempTree.FindMinValue();
    TempTree.InorderPrint();
    TempTree.PreorderPrint();

    TempTree.DeleteNode(8);
    TempTree.InorderPrint();
    TempTree.PreorderPrint();

    return 0;
}
