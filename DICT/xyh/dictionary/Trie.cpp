#include<iostream>
#include<fstream>
#include<cstdlib>
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

        if(str.Vocabulary[i] - '-'==0)
        {
            index=26;
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
void Trie::SearchWord()
{
    cout<<"请输入您想要查询的单词"<<endl;
    string str;
    cin>>str;
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';
        if((index < 0 || index > 25)&&(str[i] - '-'!=0))//若不是英文单词，报错
        {
            cout<<"你输入单词中有错误的字符"<<endl;
            return;
        }
    if(str[i] - '-'==0)
    {
        index=26;
    }
        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在，说明没有此单词
        {
            cout<<"单词不存在"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词存在，打印
    {
        cout<<pLoc->TheWord.Vocabulary<<"   "<<pLoc->TheWord.Chinese<<"   "<<pLoc->TheWord.WordCharacter<<endl;
        return;
    }
    else    //若单词不存在，说明没有此单词
    {
        cout<<"单词不存在"<<endl;
            return;
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
void Trie::ReadData()
{
    string V,C,WC;
    Word WordData;
    ifstream infile("dictionary.txt",ios::in);//以输入的方式打开文件
    if(!infile)
    {
        cout<<"词典打开错误"<<endl;
        exit(1);
    }
    while(!infile.eof())
    {
        infile>>V>>C>>WC;
        WordData.Set(V,C,WC);
        InsertWord(WordData);
    }
    infile.close();
};
