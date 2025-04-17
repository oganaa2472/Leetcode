struct Node {
    unordered_map<int, Node*> links;
    int cnt = 0;
    void put(int n, Node* node) {
        links[n] = node;
    }
    Node* get(int node) {
        return links[node];
    }
    bool containsKeys(int node) {
        return links.count(node) > 0; // Fixing the check
    }
};
class Solution {
public:
    Node* root;
    Solution() {
        root = new Node();
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        for (string& word : words) {
            Node* curr = root;
            int n = word.size();
            for (int j = 0; j < n; j++) {
                int node = 128 * word[j] + word[n - j - 1];
                if (!curr->containsKeys(node)) {
                    curr->put(node, new Node());
                }
                curr = curr->get(node);
                ans += curr->cnt;
            }
            curr->cnt++;
        }
        return ans;
    }
};