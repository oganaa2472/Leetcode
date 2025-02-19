class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
    
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string scs = "";
        int i = n;
        int j = m;
        while(i>0||j>0){
            if(i>0&&j>0&&text1[i-1]==text2[j-1]){
                scs+=text1[i-1];
                i--,j--;
            }
            else if (j > 0 && (i == 0 || dp[i][j - 1] >= dp[i - 1][j])) {
                scs += text2[j - 1];
                j--;
            } else {
                scs += text1[i - 1];
                i--;
            }
        }
        reverse(scs.begin(),scs.end());
        return scs;
    }
};