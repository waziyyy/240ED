#ifndef TRIE_H
#define TRIE_H
#include<fstream>
#include <iostream>
#include<cstdlib>
#include <string>
#include "Word.h"
#include"TrieNode.h"
class Trie
{
public:
    Trie();
    ~Trie();
    void InsertWord(Word str);
    void SearchWord();
    void ReadData();
private:
    TrieNode* pRoot;
    void Destroy(TrieNode* pRoot);//Ïú»ÙTrieÊ÷
};


#endif // TRIE_H
