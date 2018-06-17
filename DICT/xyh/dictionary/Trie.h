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
    void SearchWord();//��������,�ڲ����뵥��
    void SearchWord(string str);//��������,�ⲿ���ݵ���
    void BlurSearch();//ģ��������,�ڲ����뵥��
    void BlurSearch(string str);//ģ��������,�ⲿ���ݵ���
private:
    TrieNode* pRoot;//���ڵ�
    void Destroy(TrieNode* pRoot);//����Trie��
    void ReadData();//����ʵ�����
    void PrintAll(TrieNode* p);//��ӡ�˽ڵ��µ����е���
};


#endif // TRIE_H
