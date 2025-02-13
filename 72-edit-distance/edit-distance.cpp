class Solution {
public:
    vector<vector<int>> dp;
    int n,m;

    int solve(int i,int j,string& word1,string& word2){
          if (i == n) return m - j; 
        if (j == m) return n - i;  
        
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i+1, j+1, word1, word2); 
        } else {
            return dp[i][j] = 1 + min({
                solve(i+1, j, word1, word2),  
                solve(i, j+1, word1, word2),   
                solve(i+1, j+1, word1, word2)   
            });
        }
    }
    int minDistance(string word1, string word2) {

        n = word1.size(), m = word2.size();
        dp.resize(n, vector<int>(m, -1));  // 0-based тул `dp[n][m]` биш `dp[n-1][m-1]`
        return solve(0, 0, word1, word2);
    }
};