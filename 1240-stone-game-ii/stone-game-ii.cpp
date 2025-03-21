class Solution {
private:
    vector<vector<vector<int>>> dp;

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return dfs(1, 0, 1, piles);
    }

private:
    int dfs(int alice, int i, int M, vector<int>& piles) {
        if (i == piles.size()) return 0;
        if (dp[alice][i][M] != -1) return dp[alice][i][M];

        int res = alice == 1 ? 0 : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++) {
            if (i + X > piles.size()) break;
            total += piles[i + X - 1];
            if (alice == 1) {
                res = max(res, total + dfs(0, i + X, max(M, X), piles));
            } else {
                res = min(res, dfs(1, i + X, max(M, X), piles));
            }
        }

        dp[alice][i][M] = res;
        return dp[alice][i][M];
    }
};