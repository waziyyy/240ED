#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Trie.h"
#include<string>
#include<string.h>
using namespace std;
/*
        Ӣ�������ַ�
        '  ascii  39    �ֵ�λ��27
         / ascii 47     �ֵ�λ��28
         -              �ֵ�λ��26
*/
Trie::Trie()
{
    pRoot=new TrieNode();//�ֵ�ĸ�������ַ�
    ReadData();//����ʵ�����
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

    if((index>=-32)&&(index<=-7))
        {
            index=index+32;
        }
        if((index < 0 || index > 25)&&(str.Vocabulary[i] - '-'!=0)&&(str.Vocabulary[i]!=39)&&(str.Vocabulary[i]!=47))//������Ӣ�ĵ��ʣ���ִ�в���
        {
            cout<<"wrong"<<endl;
            cout<<str.Vocabulary[i]<<endl;
            return;
        }

        if(str.Vocabulary[i] - '-'==0)
        {
            index=26;
        }
        if(str.Vocabulary[i] ==39)
        {
            index=27;
        }
        if(str.Vocabulary[i] ==47)
        {
            index=28;
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
    cout<<"����������Ҫ��ѯ�ĵ��ʣ�ģ���������ѹرգ�"<<endl;
    string str;
    cin>>str;
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';
        if((index>=-32)&&(index<=-7))
        {
            index=index+32;
        }
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//������Ӣ�ĵ��ʣ�����
        {
            cout<<"�����뵥�����д�����ַ�"<<endl;
            return;
        }
    if(str[i] - '-'==0)
    {
        index=26;
    }
    if(str[i] ==39)
    {
        index=27;
    }
        if(str[i] ==47)
    {
        index=28;
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
        pLoc->TheWord.PrintWord();
    }
    else    //�����ʲ����ڣ�˵��û�д˵���
    {
        cout<<"���ʲ�����"<<endl;
            return;
    }
};
void Trie::SearchWord(string str)
{
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';
        if((index>=-32)&&(index<=-7))
        {
            index=index+32;
        }
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//������Ӣ�ĵ��ʣ�����
        {
            cout<<"�����뵥�����д�����ַ�"<<endl;
            return;
        }
    if(str[i] - '-'==0)
    {
        index=26;
    }
    if(str[i] ==39)
    {
        index=27;
    }
    if(str[i] ==47)
    {
        index=28;
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
        pLoc->TheWord.PrintWord();
    }
    else    //�����ʲ����ڣ�˵��û�д˵���
    {
        cout<<"���ʲ�����"<<endl;
            return;
    }
};
void Trie::BlurSearch()
{
    cout<<"����������Ҫ��ѯ�ĵ��ʣ�ģ���������ѿ�����"<<endl;
    string str;
    cin>>str;
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';

        if((index>=-32)&&(index<=-7))
        {
            index=index+32;
        }
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//������Ӣ�ĵ��ʣ�����
        {
            cout<<"�����뵥�����д�����ַ�"<<endl;
            return;
        }
    if(str[i] - '-'==0)
    {
        index=26;
    }
    if(str[i] ==39)
    {
        index=27;
    }
    if(str[i] ==47)
    {
        index=28;
    }
        if (NULL == pLoc->NextBranch[index])//�õ��ʵ�ǰ׺�����ڣ�˵��û�д˵���
        {
            cout<<"����ǰ׺�����ڣ�ģ��������ʧ��"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//�����ʴ��ڣ���ӡ
    {
        pLoc->TheWord.PrintWord();
        return;
    }
    else    //�����ʲ����ڣ�ģ��������
    {
        //��ӡ��������ַ�Ϊǰ׺�������һλ�����е���
       /* cout<<"��ʼģ��������"<<endl;
        trienode* pblur =null;
        for(int i=0;i<num;i++)
        {
            if(ploc->nextbranch[i]!=null)
            {
                pblur=ploc->nextbranch[i];
                if(pblur->haveword)
                    {
                        pblur->theword.printword();
                    }
            }
        }*/

        //��ӡ�������ַ�Ϊǰ׺�����е���
            PrintAll(pLoc);

    }
};
void Trie::BlurSearch(string str)
{
    int index;
    TrieNode* pLoc =pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';

        if((index>=-32)&&(index<=-7))
        {
            index=index+32;
        }
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//������Ӣ�ĵ��ʣ�����
        {
            cout<<"�����뵥�����д�����ַ�"<<endl;
            return;
        }
    if(str[i] - '-'==0)
    {
        index=26;
    }
    if(str[i] ==39)
    {
        index=27;
    }
    if(str[i] ==47)
    {
        index=28;
    }
        if (NULL == pLoc->NextBranch[index])//�õ��ʵ�ǰ׺�����ڣ�˵��û�д˵���
        {
            cout<<"����ǰ׺�����ڣ�ģ��������ʧ��"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//�����ʴ��ڣ���ӡ
    {
        pLoc->TheWord.PrintWord();
        return;
    }
    else    //�����ʲ����ڣ�ģ��������
    {
        //��ӡ��������ַ�Ϊǰ׺�������һλ�����е���
       /* cout<<"��ʼģ��������"<<endl;
        trienode* pblur =null;
        for(int i=0;i<num;i++)
        {
            if(ploc->nextbranch[i]!=null)
            {
                pblur=ploc->nextbranch[i];
                if(pblur->haveword)
                    {
                        pblur->theword.printword();
                    }
            }
        }*/

        //��ӡ�������ַ�Ϊǰ׺�����е���
            PrintAll(pLoc);

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

    int i=0;
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
        i++;
    }
    infile.close();
    cout<<"�ʿ⹲��"<<i<<"��"<<endl;
};
void Trie::PrintAll(TrieNode *p)
{
    if(p==NULL)
    {
        return;
    }
    if(p->HaveWord)
    {
        p->TheWord.PrintWord();
    }
    for(int i=0;i<NUM;i++)
    {
        PrintAll(p->NextBranch[i]);
    }
};
