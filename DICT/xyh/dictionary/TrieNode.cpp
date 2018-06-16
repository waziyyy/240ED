#include <iostream>
#include "TrieNode.h"
#include <string>

using namespace std;
TrieNode::TrieNode()
{
    HaveWord=false;
    int i=0;
    for(i=0;i<NUM;i++)
    {
        NextBranch[i]=NULL;
    }
};
TrieNode::~TrieNode()
{

};
