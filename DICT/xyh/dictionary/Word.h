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
    Word();//���캯��
    Word(string V,string C,string WC);//���캯��������
    void Set(string V,string C,string WC);//���õ��ʵ�Ӣ�ģ����ģ�����
    void PrintWord();
    ~Word();//��������
    string Vocabulary;//Ӣ�ĵ���
    string Chinese;//���Ľ���
    string WordCharacter;//����
};


#endif // WORD_H
