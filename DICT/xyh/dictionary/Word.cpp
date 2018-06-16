#include <iostream>
#include "Word.h"
#include <string>
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
Word::~Word()
{

};
