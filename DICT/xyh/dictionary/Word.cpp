#include <iostream>
#include "Word.h"
#include <string>
#include<fstream>
#include<cstdlib>
using namespace std;
Word::Word()
{
    Vocabulary="";
    Chinese="";
    WordCharacter="";
};
Word::Word(string V,string C,string WC)
{
    Vocabulary=V;
    Chinese=C;
    WordCharacter=WC;
};
void Word::Set(string V,string C,string WC)
{
    Vocabulary=V;
    Chinese=C;
    WordCharacter=WC;
};
void Word::PrintWord()
{
    cout<<Vocabulary<<"   "<<Chinese<<"   "<<WordCharacter<<endl;
};
Word::~Word()
{

};
