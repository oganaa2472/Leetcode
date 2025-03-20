class Solution {
public:
    int n;
    int m;
    int z;
    string s1,s2,s3;
    bool solve(int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i==n&&j==m&&k==z) return true;
        if(i>n||j>m||k>z) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans = false;
        if(s1[i]==s3[k]){
            ans |= solve(i+1,j,k+1,dp);
        }
        if(s2[j]==s3[k]){
            ans |= solve(i,j+1,k+1,dp);
        }
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1; 
        this->s2 = s2;
        this->s3 = s3;
        n = s1.size();
        m = s2.size();
        z = s3.size();
        vector<vector<vector<int>>> dp(101,vector<vector<int>>(100+1,vector<int>(201,-1)));
        return solve(0,0,0,dp);
    }
};