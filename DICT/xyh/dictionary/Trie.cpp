#include<iostream>
#include"Trie.h"
#include<string>
#include<string.h>
using namespace std;
Trie::Trie()
{
    pRoot=new TrieNode();//字典的根不存放字符
};
Trie::~Trie()
{
    Destroy(pRoot);
};
void Trie::InsertWord(Word str)
{
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str.Vocabulary[i];i++)
    {
        index = str.Vocabulary[i] - 'a';

        if((index < 0 || index > 25)&&(str.Vocabulary[i] - '-'!=0))//若不是英文单词，不执行插入
        {
            return;
        }

        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在，要生成该结点
        {
            pLoc->NextBranch[index] = new TrieNode();
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词已经出现过
    {
        return;
    }
    else    //若单词没有出现过，应该插入单词
    {
        pLoc->TheWord=str;
        pLoc->HaveWord=true;
    }
};
void Trie::SearchWord(string str)
{

    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';

        if((index < 0 || index > 25)&&(str.Vocabulary[i] - '-'!=0))//若不是英文单词，报错
        {
            cout<<"你输入单词中有错误的字符"<<endl;
            return;
        }

        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在
        {
            cout<<"单词不存在"<<endl;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词已经出现过
    {
        return;
    }
    else    //若单词没有出现过，应该插入单词
    {
        pLoc->TheWord=str;
        pLoc->HaveWord=true;
    }
};
void Trie::Destroy(TrieNode* pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    for (int i = 0;i < NUM;i++)
    {
      Destroy(pRoot->NextBranch[i]);
    }
    delete pRoot;//销毁结点
    pRoot = NULL;
};
