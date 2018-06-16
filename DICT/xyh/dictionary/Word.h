#ifndef WORD_H
#define WORD_H
#include <iostream>
#include<fstream>
#include <string>
#include<cstdlib>

using namespace std;
class Word
{
public:
    Word();//构造函数
    Word(string V,string C,string WC);
    void Set(string V,string C,string WC);//设置单词的英文，中文，词性
    ~Word();//析构函数
    string Vocabulary;//英文单词
    string Chinese;//中文解释
    string WordCharacter;//词性
};


#endif // WORD_H
