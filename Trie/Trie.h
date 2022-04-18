#pragma once
#include <string>
#include <iostream>

#pragma once

using std::string;
using std::cout;
using std::endl;

const int ALPHABET_SIZE = 26;

struct Node {
    char c;
    bool eow;
    Node* symbols[ALPHABET_SIZE];

public:
    Node(char symbol)
    {
        c = symbol;
        eow = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            symbols[i] = nullptr;
    }

    Node(const Node& node)
    {
        c = node.c;
        eow = node.eow;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            symbols[i] = node.symbols[i];
    }
};

class Trie {
private:
    Node* root;

    bool remove(Node*& node, string word, int h);
    void removeRec(Node*& node, string sub_string, int h, string curr);
    bool hasChilds(Node* node);
    void deleteAll(Node*& curNode);
public:
    Trie();
    ~Trie();
    void insert(string s);
    bool find(string s);
    bool remove(string s);
    void clear();
    void print();
    void removeSubString(string s);

};