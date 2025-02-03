class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int target){
        if(target<0) return INT_MAX;
        if(target==0){
            return 0;
        }
        if(dp[target]!=-1) return dp[target];
        int answer = INT_MAX;
        for(int i = 1;i*i<=target;i++){
            answer=min(answer,1+solve(target-(i*i)));
        }
        return dp[target] = answer;
    }
    int numSquares(int n) {
        this->n = n;
        int target = n;
        dp.resize(n+1,-1);
        return solve(target);
    }
};