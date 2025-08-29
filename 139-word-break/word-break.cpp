#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // store child nodes
    bool isEndOfWord; // true if this node represents the end of a word

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string &prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return true;
    }
};

class Solution {
public:

    bool solve(string s, Trie* t, unordered_map<string,bool>& memo){
        if(s.size() == 0) return true;
        if(memo.count(s)) return memo[s];

        for(int i = 0; i < s.size(); i++){
            string firstHalves = s.substr(0, i + 1);
            string secondHalves = s.substr(i + 1);
            if(t->search(firstHalves) && solve(secondHalves, t, memo)){
                memo[s] = true;
                return true;
            }
        }
        memo[s] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for(string &word : wordDict) trie->insert(word);
        unordered_map<string,bool> memo;
        return solve(s, trie, memo);
    }

};