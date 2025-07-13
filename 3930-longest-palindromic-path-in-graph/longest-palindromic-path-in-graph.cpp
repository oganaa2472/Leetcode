class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // 1) portable allocation
    vector<vector<vector<char>>> dp(1 << n,
        vector<vector<char>>(n, vector<char>(n, 0)));

    // 2) initial states
    for (int v = 0; v < n; ++v) dp[1 << v][v][v] = 1;
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            if (label[u] == label[v])
                dp[(1 << u) | (1 << v)][u][v] = 1;

    int ans = 1;
    for (int mask = 1; mask < (1 << n); ++mask)
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                for (int j = 0; j < n; ++j)
                    if ((mask & (1 << j)) && dp[mask][i][j]) {
                        ans = max(ans, __builtin_popcount(mask));
                        for (int ii : adj[i])
                            if (!(mask & (1 << ii)))
                                for (int jj : adj[j])
                                    if (ii != jj && !(mask & (1 << jj))
                                        && label[ii] == label[jj]) {

                                        // 3) keep previous mask bits
                                        int newMask = mask | (1 << ii) | (1 << jj);
                                        dp[newMask][ii][jj] = 1;
                                    }
                    }
    return ans;
}

};