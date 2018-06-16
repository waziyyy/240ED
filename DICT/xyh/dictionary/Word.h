#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>

using namespace std;
class Word
{
public:
    Word();//构造函数
    Word(string V,string C,string WC);
    ~Word();//析构函数
    string Vocabulary;//英文单词
    string Chinese;//中文解释
    string WordCharacter;//词性
};


#endif // WORD_H
