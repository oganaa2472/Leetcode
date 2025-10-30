class Solution {
public:
    int solve(int i,int j, string& t1,string& t2,vector<vector<int>>& dp){
        int n = t1.size();
        int m = t2.size();
        // base case
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n - i;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i]==t2[j]){
            return dp[i][j] = solve(i+1,j+1,t1,t2,dp);
        }
        return dp[i][j] = 1 + min({
                solve(i+1, j, t1, t2,dp),  
                solve(i, j+1, t1, t2,dp),   
                solve(i+1, j+1, t1, t2,dp)   
            });
        
    }
    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,text1,text2,dp);
    }
};