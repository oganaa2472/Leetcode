class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string s){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==j) return dp[i][j]=1;

        if(s[i]==s[j]) 
            return dp[i][j]=2+solve(i+1,j-1,s);
        
        int firstChoose = solve(i+1,j,s);
        int secondChoose = solve(i,j-1,s);
        return dp[i][j] = max(firstChoose,secondChoose);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> prev(n, 0), curr(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1; 
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    curr[j] = 2 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;  
        }
        return curr[n - 1];
    }
};