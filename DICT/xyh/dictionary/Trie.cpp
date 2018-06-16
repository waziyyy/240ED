#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Trie.h"
#include<string>
#include<string.h>
using namespace std;
Trie::Trie()
{
    pRoot=new TrieNode();//�ֵ�ĸ�������ַ�
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

        if((index < 0 || index > 25)&&(str.Vocabulary[i] - '-'!=0))//������Ӣ�ĵ��ʣ���ִ�в���
        {
            return;
        }

        if(str.Vocabulary[i] - '-'==0)
        {
            index=26;
        }
        if (NULL == pLoc->NextBranch[index])//�õ��ʵ�ǰ׺�����ڣ�Ҫ���ɸý��
        {
            pLoc->NextBranch[index] = new TrieNode();
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//�������Ѿ����ֹ�
    {
        return;
    }
    else    //������û�г��ֹ���Ӧ�ò��뵥��
    {
        pLoc->TheWord=str;
        pLoc->HaveWord=true;
    }
};
void Trie::SearchWord()
{
    cout<<"����������Ҫ��ѯ�ĵ���"<<endl;
    string str;
    cin>>str;
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';
        if((index < 0 || index > 25)&&(str[i] - '-'!=0))//������Ӣ�ĵ��ʣ�����
        {
            cout<<"�����뵥�����д�����ַ�"<<endl;
            return;
        }
    if(str[i] - '-'==0)
    {
        index=26;
    }
        if (NULL == pLoc->NextBranch[index])//�õ��ʵ�ǰ׺�����ڣ�˵��û�д˵���
        {
            cout<<"���ʲ�����"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//�����ʴ��ڣ���ӡ
    {
        cout<<pLoc->TheWord.Vocabulary<<"   "<<pLoc->TheWord.Chinese<<"   "<<pLoc->TheWord.WordCharacter<<endl;
        return;
    }
    else    //�����ʲ����ڣ�˵��û�д˵���
    {
        cout<<"���ʲ�����"<<endl;
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
    delete pRoot;//���ٽ��
    pRoot = NULL;
};
void Trie::ReadData()
{
    string V,C,WC;
    Word WordData;
    ifstream infile("dictionary.txt",ios::in);//������ķ�ʽ���ļ�
    if(!infile)
    {
        cout<<"�ʵ�򿪴���"<<endl;
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
