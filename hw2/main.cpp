#include "BinTree.h"
#include "BinTree.cpp"

int main()
{
    BinTree tree("dictionary.txt", "cat", "dog");
    tree.buildTree();
}