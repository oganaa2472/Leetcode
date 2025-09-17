#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    int children[26];
    int index;
    int len;

    TrieNode() {
        isEnd = false;
        index = INT_MAX;
        len = INT_MAX;
        for (int i = 0; i < 26; i++) children[i] = -1;
    }
};

class Trie {
public:
    vector<TrieNode> pool;  // pool of nodes
    int root;

    Trie() {
        
        pool.push_back(TrieNode());
        root = 0;
    }

    void insert(const string& word, int wordIndex) {
        int node = root;
        for (char ch : word) {
            int ci = ch - 'a';
            if (pool[node].children[ci] == -1) {
                pool[node].children[ci] = pool.size();
                pool.push_back(TrieNode());
            }
            int nxt = pool[node].children[ci];
            if (word.size() < pool[nxt].len) {
                pool[nxt].len = word.size();
                pool[nxt].index = wordIndex;
            }
            node = nxt;
        }
        pool[node].isEnd = true;
    }

    int search(const string& word) {
        int node = root;
        for (char c : word) {
            int ci = c - 'a';
            if (pool[node].children[ci] == -1) return pool[node].index;
            node = pool[node].children[ci];
        }
        return pool[node].index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) { 
        Trie trie;
        int mn = INT_MAX;
        int minIndex = -1;

        // Insert all container words (reversed)
        for (int i = 0; i < (int)wordsContainer.size(); i++) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            if ((int)wordsContainer[i].size() < mn) {
                mn = wordsContainer[i].size();
                minIndex = i;
            }
            trie.insert(wordsContainer[i], i);
        }   

        int n = wordsQuery.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());
            int t = trie.search(wordsQuery[i]);
            ans[i] = (t == INT_MAX ? minIndex : t);
        }
        return ans;
    }
};
