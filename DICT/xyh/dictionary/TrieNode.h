#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <string>
#include "Word.h"
#define NUM 26
using namespace std;
class TrieNode
{
public:
    TrieNode();
    ~TrieNode();
    bool HaveWord;//判断该节点是否存在单词
    Word TheWord;//记录该节点单词的数据
    TrieNode* NextBranch[NUM];//指向子节点
};

#endif // TRIENODE_H
