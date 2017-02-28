#include "BinTree.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <locale>
using namespace std;

BinTree::BinTree(string dictionary, string firstWord, string lastWord)
{
    startWord = firstWord;
    endWord = lastWord;
    
    root = new Node;
    root->word = firstWord;
    usedWords.push_back(firstWord);
    
    if(firstWord.length() != lastWord.length())
    {
        cout << "Words are not the same length!" << endl;
        exit(1);
    }
    else
    {
    std::ifstream file;
    std::string line;
    
    file.open(dictionary);
    if(!file)
    {
        std::cout << "Couldn't open file" << std::endl;
    }
    if(file.is_open())
    {
        while (std::getline(file, line))
        {
            //Borrowed code to get rid of non-printable character at the end of
            //every line.
            line.erase(remove_if(line.begin(), line.end(), [](char c) { return !isalpha(c); } ), line.end());
            if(line.length() == startWord.length())
            {
                dict.push_back(line);
            }
            
        }
    }
    file.close();
    }
    if(!findInDict(firstWord))
    {
        cout << firstWord << " not found in dictionary" << endl;
        exit(1);
    }
    if(!findInDict(lastWord))
    {
        cout << lastWord << " not found in dictiionary" << endl;
        exit(1);
    }
    
}

void BinTree::buildTree()
{
    root->children = getChildren(startWord);
    string first = buildLevel(root->children);
    cout << "From " << startWord << " to " << endWord << ": " << endl;
    printTree(root, root->word);
}

string BinTree::buildLevel(vector<Node*> children)
{
    for(Node* k : children)
    {
        if(k->word == endWord)
        {
            return k->word;
        }
    }
    
    vector<Node*> nextLevel;
    for(Node* k : children)
    {
        k->children = getChildren(k->word);
        for(Node* c : k->children)
        {
            nextLevel.push_back(c);
        }
    }
    
    for(Node* k : children)
    {
        usedWords.push_back(k->word);
    }
    
    string rtnString = buildLevel(nextLevel);
    cout << rtnString << endl;
    for(Node* n : nextLevel)
    {
        if(n->word == rtnString)
        {
            return n->parentWord;
        }
    }
}

vector<Node*> BinTree::getChildren(string first)
{
    vector<Node*> rtnVector;
    for(auto word : dict)
        {
            if(isOneLetterOff(first, word) && !hasBeenUsed(word))
            {
                Node* temp = new Node(word, first);
                rtnVector.push_back(temp);
            }
        }
        return rtnVector;
    
}

bool BinTree::isOneLetterOff(string base, string test)
{
    int numDiff = 0;
    if(base.length() == test.length())
    {
        for(int i = 0; i < base.length(); i++)
        {
            if(numDiff > 1)
            {
                return false;
            }
            if(base[i] != test[i])
            {
                numDiff++;
            }
        }
        if(numDiff <= 1)
        {
            return true;
        }
    }
    return false;
}

void BinTree::printTree(Node* n, string parent)
{
    cout << parent << endl;
    for(Node* node : n->children)
    {
        if(endWord == node->word)
        {
            cout << "******* Found Ladder ********" << endl;
        }
        printTree(node, parent+"->"+node->word);
    }
}

bool BinTree::hasBeenUsed(string word)
{
    sort(usedWords.begin(), usedWords.end());
    return binary_search(usedWords.begin(), usedWords.end(), word);
}

bool BinTree::findInDict(string word)
{
    sort(dict.begin(), dict.end());
    return binary_search(dict.begin(), dict.end(), word);
}

