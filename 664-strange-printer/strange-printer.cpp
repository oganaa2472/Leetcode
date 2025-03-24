class Solution {
public:

    vector<vector<int>> dp;
    int n ;
    string s;
    int solve(int i,int j){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int minNum = INT_MAX;
        for(int k = i ;k<j;k++){
            int print = solve(i,k)+solve(k+1,j);
            minNum = min(minNum,print);
        }

        return dp[i][j] = s[i]==s[j] ? minNum-1:minNum;
    }
    int strangePrinter(string s) {
        this->s = s;
        n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));

        return solve(0,n-1);
    }
};