class Solution {
public:
    string s;
    string p;
    bool isCheck(int i){
        bool isStar=false;
        for(int j=i;j>=1;j--){
            if(p[j-1]!='*'&&isStar==false) {
                return false;
            }else if(p[j-1]=='*'){
                j--;
            }

        }
        return true;
    }
    bool solve(int i,int j,vector<vector<int>>& dp){
        if (i == 0 && j == 0) return true;
        if (j == 0 && i > 0) return false;
        if (i == 0 && j > 0) {
            if (p[j - 1] == '*')
                return solve(i, j - 2, dp);
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1]||p[j-1]=='.')
        {
            return dp[i][j] = solve(i-1,j-1,dp);
        }
        if(p[j-1]=='*'){
            if (j >= 2 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                return dp[i][j] = solve(i - 1, j, dp) || solve(i, j - 2, dp);
            }
            return dp[i][j] = solve(i, j - 2, dp);
    

        }
       
            
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        this->s=s;
        this->p = p;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,dp);
    }
};