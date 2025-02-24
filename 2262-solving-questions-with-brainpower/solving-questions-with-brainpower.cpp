class Solution {
public:
    vector<long long> dp;
    vector<vector<int>> q;
    int n;
    long long solve(int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long exclude = solve(i+1);
        long long include = q[i][0]+solve(i + q[i][1] + 1);
        return dp[i]= max(exclude,include);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.resize(n,-1);
        this->q=questions;
        return solve(0);

    }
};