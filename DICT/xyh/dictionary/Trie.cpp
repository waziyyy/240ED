#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Trie.h"
#include<string>
#include<string.h>
using namespace std;
/*
        英文特殊字符
        '  ascii  39    字典位置27
         / ascii 47     字典位置28
         -              字典位置26
*/
Trie::Trie()
{
    pRoot=new TrieNode();//字典的根不存放字符
    ReadData();//读入词典数据
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
        if((index < 0 || index > 25)&&(str.Vocabulary[i] - '-'!=0)&&(str.Vocabulary[i]!=39)&&(str.Vocabulary[i]!=47))//若不是英文单词，不执行插入
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
    cout<<"请输入您想要查询的单词（模糊化搜索已关闭）"<<endl;
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
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//若不是英文单词，报错
        {
            cout<<"你输入单词中有错误的字符"<<endl;
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
        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在，说明没有此单词
        {
            cout<<"单词不存在"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词存在，打印
    {
        pLoc->TheWord.PrintWord();
    }
    else    //若单词不存在，说明没有此单词
    {
        cout<<"单词不存在"<<endl;
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
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//若不是英文单词，报错
        {
            cout<<"你输入单词中有错误的字符"<<endl;
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
        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在，说明没有此单词
        {
            cout<<"单词不存在"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词存在，打印
    {
        pLoc->TheWord.PrintWord();
    }
    else    //若单词不存在，说明没有此单词
    {
        cout<<"单词不存在"<<endl;
            return;
    }
};
void Trie::BlurSearch()
{
    cout<<"请输入您想要查询的单词（模糊化搜索已开启）"<<endl;
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
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//若不是英文单词，报错
        {
            cout<<"你输入单词中有错误的字符"<<endl;
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
        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在，说明没有此单词
        {
            cout<<"单词前缀不存在，模糊化搜索失败"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词存在，打印
    {
        pLoc->TheWord.PrintWord();
        return;
    }
    else    //若单词不存在，模糊化搜索
    {
        //打印以输入的字符为前缀，比其多一位的所有单词
       /* cout<<"开始模糊化搜索"<<endl;
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

        //打印以输入字符为前缀的所有单词
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
        if((index < 0 || index > 25)&&(str[i] - '-'!=0)&&(str[i]!=39)&&(str[i]!=47))//若不是英文单词，报错
        {
            cout<<"你输入单词中有错误的字符"<<endl;
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
        if (NULL == pLoc->NextBranch[index])//该单词的前缀不存在，说明没有此单词
        {
            cout<<"单词前缀不存在，模糊化搜索失败"<<endl;
            return;
        }
        pLoc = pLoc->NextBranch[index];
    }
    if (pLoc->HaveWord)//若单词存在，打印
    {
        pLoc->TheWord.PrintWord();
        return;
    }
    else    //若单词不存在，模糊化搜索
    {
        //打印以输入的字符为前缀，比其多一位的所有单词
       /* cout<<"开始模糊化搜索"<<endl;
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

        //打印以输入字符为前缀的所有单词
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
    delete pRoot;//销毁结点
    pRoot = NULL;
};
void Trie::ReadData()
{
    string V,C,WC;

    int i=0;
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
        i++;
    }
    infile.close();
    cout<<"词库共有"<<i<<"词"<<endl;
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
