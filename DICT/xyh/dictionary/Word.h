#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>

using namespace std;
class Word
{
public:
    Word();//���캯��
    Word(string V,string C,string WC);
    ~Word();//��������
    string Vocabulary;//Ӣ�ĵ���
    string Chinese;//���Ľ���
    string WordCharacter;//����
};


#endif // WORD_H
