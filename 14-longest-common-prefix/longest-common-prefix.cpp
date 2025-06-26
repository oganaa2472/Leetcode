class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int linkCount;  // To count the number of children

    TrieNode() : isEnd(false), linkCount(0) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    void put(char ch, TrieNode* node) {
        if (children[ch - 'a'] == nullptr) {
            children[ch - 'a'] = node;
            linkCount++;
        }
    }

    bool contains(char ch) { return children[ch - 'a'] != nullptr; }

    int getLinks() const { return linkCount; }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new TrieNode());
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    string searchLongestPrefix(string word) {
        TrieNode* node = root;
        string prefix;
        for (char c : word) {
            if (node->contains(c) && node->getLinks() == 1 && !node->isEnd) {
                prefix += c;
                node = node->children[c - 'a'];
            } else {
                break;
            }
        }
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        Trie trie;
        for (int i = 1; i < strs.size(); i++) {
            trie.insert(strs[i]);
        }
        return trie.searchLongestPrefix(strs[0]);
    }
};