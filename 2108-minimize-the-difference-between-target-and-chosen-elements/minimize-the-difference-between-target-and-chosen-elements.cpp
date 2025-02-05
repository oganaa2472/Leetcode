class Solution {
public:
    vector<vector<int>> mat;
    int n;
    int m;
    int target;
    vector<vector<int>> dp;
    int solve(int i,int sum){
        if(i==n){
            return abs(target-sum);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int k = INT_MAX;
        for(auto c:mat[i]){
            k = min(k,solve(i+1,sum+c));
        }
        return dp[i][sum] = k;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        
        this->target=target;
        dp.resize(n,vector<int>(70*800,-1));
        return solve(0,0);
    }
};