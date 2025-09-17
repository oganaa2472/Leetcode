struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
    
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    void dfs(TrieNode* cur, string& word, string& result) {
        if (cur->isEnd) {
            if (result.empty() || word.size() > result.size() || 
               (word.size() == result.size() && word < result)) {
                result = word;
            }
        }

        for (char i = 'a'; i <= 'z'; i++) {
            if (cur->children[i - 'a'] && cur->children[i - 'a']->isEnd) {
                word.push_back(i);
                dfs(cur->children[i - 'a'], word, result);
                word.pop_back();
            }
        }
    }

    string longest() {
        string word = "";
        string result = "";
        dfs(root, word, result);
        return result;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& word : words) {
            trie->insert(word);
        }
        return trie->longest();
    }
};
