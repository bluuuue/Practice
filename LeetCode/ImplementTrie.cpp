#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        
    }
    vector<string> trie;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        root->trie.push_back(word);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        bool bGot = false;
        for (int i = 0; i < root->trie.size(); ++i)
        {
            if (root->trie[i] == word)
            {
                bGot = true;
                break;
            }
        }
        return bGot;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        bool bGot = false;
        for (int i = 0; i < root->trie.size(); ++i)
        {
            int nPreLen = prefix.size();
            if (root->trie[i].size() >= nPreLen)
            {
                string temp(root->trie[i], 0, nPreLen);
                if (temp == prefix)
                {
                    bGot = true;
                    break;
                }
            }
        }
        return bGot;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie test;
    test.insert("aaa");
    test.insert("bbb");
    test.insert("ccc");
    test.insert("ddd");
    cout << test.search("ccc") << endl;
    cout << test.search("mcc") << endl;
    cout << test.startsWith("c") << endl;

    return 0;
}
