#include <iostream>
#include<string>
#include"Word.h"
#include"TrieNode.h"
#include"Trie.h"
using namespace std;

int main()
{
    Trie first;

    first.ReadData();

    first.SearchWord();
    return 0;
}
