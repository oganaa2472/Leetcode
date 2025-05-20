class TreeAncestor {
public:
    vector<vector<int>> dp;
    int nodes;
    
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n, vector<int>(16, -1)); // 16 is chosen as 2^16 > 50000 (max n)
        nodes = n;

        // Initialize the first ancestor (parent) of each node
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }

        // Precompute the 2^j-th ancestor for all nodes
        for (int j = 1; j < 16; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j - 1] != -1) {
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
         if (k >= nodes || node < 0) {
            return -1;
        }
         int x = 0;
        while (k > 0 && node != -1) {
            if (k % 2 == 1) {
                node = dp[node][x];
            }
            x++;
            k = k >> 1; // Equivalent to k /= 2
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */