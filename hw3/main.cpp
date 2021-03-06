#include "BinarySearchTree.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
   std::vector<int> nums;
   
   //Open nums.txt and store all the numbers in 'nums' array.
   std::ifstream txt;
   std::string line;
   std::vector<std::string> strVec;
   txt.open("nums.txt");
   if(txt.is_open())
   {
       while(std::getline(txt, line))
       {
          line.erase(remove_if(line.begin(), line.end(), [](char c) { return !isdigit(c); } ), line.end());
          strVec.push_back(line);
       }
   }
   txt.close();
   
   for(auto str : strVec)
   {
       nums.push_back(stoi(str));
   }
   
   //Code to loop though the vector containing the numbers to be inserted into BST.
   //Prints the entire tree in-order, displaying the height each time.
   //Also prints to output.txt.
   BinarySearchTree<int> tree;
   tree.out.open("output.txt");
   for(auto num : nums)
   {
       tree.insert(num);
       tree.display();
       tree.outputTree();
       tree.out << "Tree Height: " << tree.height() << std::endl;
       std::cout << "Tree Height: " << tree.height() << std::endl;
   }
   
   
   tree.out.close();
   
   
}