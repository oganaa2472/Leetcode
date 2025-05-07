class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j,string& t1,string& t2){
        if(i==n||j==m){
            return 0;
        }   
        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i]==t2[j]){
            return dp[i][j] = 1 + solve(i+1,j+1,t1,t2);
        }else{
            return dp[i][j] = max(solve(i + 1, j, t1, t2), solve(i, j + 1, t1, t2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        // vector<int> prev(m+1,0);
        // vector<int> curr(m+1,0);


        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=m;j++){
        //         if(text1[i-1]==text2[j-1]){
        //             curr[j] = 1 + prev[j-1];
        //         }else{
        //             curr[j] = max(prev[j],curr[j-1]);
        //         }
        //     }
        //   prev=curr;
        // }

        // return curr[m];
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=-1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
              
            }
        }
        return dp[n][m];

    }
};