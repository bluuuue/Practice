#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
       ->bWord = false;
    }
    bool->bWord;
    TrieNode *next[256]; 
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int nSize = word.size();
        if (nSize <= 0)
            return;
        TrieNode *p = root;
        int i = 0;
        while (i < nSize)
        {
            p->next[word[i]]->bWord = true;
            p = &(p->next[word[i]]);
            ++i;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int nSize = word.size();
        if (nSize <= 0)
            return false;
        int i = 0;
        TrieNode *p = root;
        while(i < nSize)
        {
            if (p->next[word[i]]->bWord == false)
                return false;
            p = &(p->next[word[i]]);
            ++i;
        }
        for(i = 0; i < 256; ++i)
        {
            if (p->next[word[i]]->bWord == true)
                return false;
        }
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
                
    }

private:
    TrieNode* root;
};

int main()
{
    TrieNode test;

    return 0;
}
