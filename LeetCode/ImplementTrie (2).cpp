#define NULL 0

const int ALPHABET_SIZE = 26;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
		m_count = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
	int m_count;
    TrieNode *children[ALPHABET_SIZE];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int i = 0;
		TrieNode *node = root;
		while (i < word.size()) {
			if (node->children[word[i] - 'a'] == NULL) {
				node->children[word[i] - 'a'] = new TrieNode();
			}
			node = node->children[word[i] - 'a'];
			i++;
		}
		node->m_count++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        
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
	cout << sizeof(TrieNode) << endl;
	Trie a;
	a.insert("st");
	return 0;
}