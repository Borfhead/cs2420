#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <vector>
#include <deque>

using namespace std;

class Node {
public:
    string word;
    string parentWord;
    vector<Node*> children;
    Node(string w, string pw)
    {
        word = w;
        parentWord = pw;
    }
    Node(){}
};

class BinTree {
public:
    BinTree(string dictionary, string firstWord, string lastWord);
    void buildTree();
    vector<Node*> getChildren(string first);
    bool isOneLetterOff(string base, string test);
    string buildLevel(vector<Node*> children);
    void printTree(Node* n, string parent);
    void print(Node* n, int index);
    bool hasBeenUsed(string word);
    bool findInDict(string word);

private:
    Node* root;
    vector<string> dict;
    vector<string> usedWords;
    string startWord;
    string endWord;

};

#endif