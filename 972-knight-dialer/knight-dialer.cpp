class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int solve(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (dp[remain][square] != 0) {
            return dp[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + solve(remain - 1, nextSquare)) % MOD;
        }
        
        dp[remain][square] = ans;
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;
        dp.resize(n + 1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + solve(n - 1, square)) % MOD;
        }
        
        return ans;
    }
};