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
    void InsertWord(Word str);//为字典排序插入单词
    void SearchWord();//搜索单词,内部输入单词
    void SearchWord(string str);//搜索单词,外部传递单词
    void BlurSearch();//模糊化搜索,内部输入单词
    void BlurSearch(string str);//模糊化搜索,外部传递单词
private:
    TrieNode* pRoot;//根节点
    void Destroy(TrieNode* pRoot);//销毁Trie树
    void ReadData();//读入词典数据
    void PrintAll(TrieNode* p);//打印此节点下的所有单词
};


#endif // TRIE_H
