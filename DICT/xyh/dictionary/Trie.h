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
    void InsertWord(Word str);//Ϊ�ֵ�������뵥��
    void SearchWord();//��������
    void BlurSearch();//ģ��������
private:
    TrieNode* pRoot;//���ڵ�
    void Destroy(TrieNode* pRoot);//����Trie��
    void ReadData();//����ʵ�����
    void PrintAll(TrieNode* p);//��ӡ�˽ڵ��µ����е���
};


#endif // TRIE_H
