#include <iostream>
#include<string>
#include"Word.h"
#include"TrieNode.h"
#include"Trie.h"
using namespace std;

int main()
{
    Trie df;
    Word fg("sll","d","s");
    Word fgl("-sllds","d","s");
    df.InsertWord(fg);
     df.InsertWord(fgl);
    return 0;
}
