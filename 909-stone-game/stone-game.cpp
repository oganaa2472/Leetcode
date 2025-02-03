class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& piles) {
            if (i > j) {
                return 0;
            }
            

            if (dp[i][j]!=-1) {
                return dp[i][j];
            }
            
           
            int chooseFirst = piles[i] - solve(i + 1, j, piles);
            int chooseLast = piles[j] - solve(i, j - 1, piles);
            dp[i][j] = max(chooseFirst, chooseLast);
            
            return dp[i][j];
        }
    
    bool stoneGame(vector<int>& piles) {
    

        int n = piles.size();
        dp.resize(n+1,vector<int> (n+1,-1));
        return solve(0,n-1,piles) > 0;

    }
};