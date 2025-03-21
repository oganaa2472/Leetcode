class Solution {
public:

    vector<vector<vector<int>>> dp;
    int n;
    int solve(int even,int i, int M,vector<int>& piles){
        if(i==piles.size()) return 0;
        if(dp[even][i][M]!=-1) return dp[even][i][M];
        
       
        int res = even == 1 ? 0 : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++) {
            if (i + X > piles.size()) break;
            total += piles[i + X - 1];
            if (even == 1) {
                res = max(res, total + solve(0, i + X, max(M, X), piles));
            } else {
                res = min(res, solve(1, i + X, max(M, X), piles));
            }
        }
        // dp[even][i][M] = res;
        return dp[even][i][M] = res;
        
    }
    int stoneGameII(vector<int>& piles)
    {   
        n = piles.size();
        dp.resize(2, vector<vector<int>>(n+1, vector<int>(n + 1, -1)));
        return solve(1, 0, 1,piles);
    }
};