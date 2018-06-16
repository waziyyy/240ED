#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include "Word.h"
#include"TrieNode.h"
class Trie
{
public:
    Trie();
    ~Trie();
    void InsertWord(Word str);
    void SearchWord(string str);
private:
    TrieNode* pRoot;
    void Destroy(TrieNode* pRoot);//Ïú»ÙTrieÊ÷
};


#endif // TRIE_H
