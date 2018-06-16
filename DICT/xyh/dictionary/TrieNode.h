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
    bool HaveWord;//�жϸýڵ��Ƿ���ڵ���
    Word TheWord;//��¼�ýڵ㵥�ʵ�����
    TrieNode* NextBranch[NUM];//ָ���ӽڵ�
};

#endif // TRIENODE_H
