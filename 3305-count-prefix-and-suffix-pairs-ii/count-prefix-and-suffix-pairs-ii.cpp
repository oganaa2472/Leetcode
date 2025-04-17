class TrieNode {
public:
    unordered_map<int, TrieNode*> child;
    int isend=0;
};
class Solution {
public:
    TrieNode* root;
     void insert(string word) {
        TrieNode* node = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int index = word[i] * 128 + word[n - 1 - i];
            if (node->child[index] == NULL) {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isend++;
    }
     long long search(string word) {
        long long cnt = 0;
        TrieNode* node = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int index = word[i] * 128 + word[n - 1 - i];
            if (node->child[index] == NULL)
                break;
            node = node->child[index];
            cnt += node->isend;
        }
        return cnt;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
         root = new TrieNode();
        long long ans = 0;
        insert(words[0]);
        int n = words.size();
        for (int i = 1; i < n; i++) {
            ans += search(words[i]);
            insert(words[i]);
        }
        return ans;
    }
};