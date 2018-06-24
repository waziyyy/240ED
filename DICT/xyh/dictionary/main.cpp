#include <iostream>
#include<string>
#include"Word.h"
#include"TrieNode.h"
#include"Trie.h"
using namespace std;

int main()
{
    string a;
    Trie first;
    while(1)
    {

       first.BlurSearch();
       first.SearchWord();
       system("pause");
    }
    return 0;
}
