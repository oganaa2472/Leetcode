class TrieNode {
public:
    TrieNode* children[26];
    int index;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        index = -1;
    }
};

class Trie {
public:
    TrieNode* root;
    vector<int> ans;

    Trie() {
        root = new TrieNode();
    }

    // 1) Destructor to free all allocated nodes
    ~Trie() {
        freeTrie(root);
    }

    void insertword(string &word, int ind, vector<string>& wordsContainer) {
        TrieNode* node = root;
        for(int i = (int)word.size() - 1; i >= 0; i--) {
            int indexChar = word[i] - 'a';
            if(node->children[indexChar] == NULL) {
                node->children[indexChar] = new TrieNode();
                node->children[indexChar]->index = ind;
            }
            node = node->children[indexChar];
            int prevIndex = node->index;
            int newIndex = ind;
            if(wordsContainer[newIndex].size() < wordsContainer[prevIndex].size()) {
                node->index = newIndex;
            }
        }
    }

    void search(string &word, int freeIndex) {
        TrieNode* node = root;
        int s = (int)word.size();
        if(node->children[word[s - 1] - 'a'] == NULL) {
            ans.push_back(freeIndex);
            return;
        } else {
            for(int i = s - 1; i >= 0; i--) {
                int indexChar = word[i] - 'a';
                if(node->children[indexChar] == NULL) {
                    ans.push_back(node->index);
                    return;
                }
                node = node->children[indexChar];
            }
            ans.push_back(node->index);
        }
    }

private:
    // 2) Helper function to recursively free all TrieNodes
    void freeTrie(TrieNode* node) {
        if(!node) return;
        for(int i = 0; i < 26; i++) {
            if(node->children[i]) {
                freeTrie(node->children[i]);
            }
        }
        delete node;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* tr = new Trie();
        int n = (int)wordsContainer.size();

        for(int i = 0; i < n; i++) {
            tr->insertword(wordsContainer[i], i, wordsContainer);
        }

        // Find the index of the smallest word
        int em = 0;
        int size = INT_MAX;
        for(int p = 0; p < n; p++) {
            if((int)wordsContainer[p].size() < size) {
                size = (int)wordsContainer[p].size();
                em = p;
            }
        }
        cout << em << endl; // if required for debugging

        int m = (int)wordsQuery.size();
        for(int i = 0; i < m; i++) {
            tr->search(wordsQuery[i], em);
        }

        vector<int> result = tr->ans;
        delete tr;  // Free the Trie (calls ~Trie()) to release memory
        return result;
    }
};