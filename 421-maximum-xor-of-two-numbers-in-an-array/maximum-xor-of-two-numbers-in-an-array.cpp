class Solution {
    struct TrieNode {
        TrieNode* children[2]; // 0 ба 1
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };

    TrieNode* root;

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->children[opposite]) {
                maxXor |= (1 << i); // энэ битийг 1 болгоно
                node = node->children[opposite];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();

        // 1. бүх тоог trie-д оруулах
        for (int num : nums) {
            insert(num);
        }

        // 2. хамгийн их XOR олох
        int ans = 0;
        for (int num : nums) {
            ans = max(ans, findMaxXor(num));
        }

        return ans;
    }
};
