class Solution {
public:
    int INF = 1e9+7;
    vector<int> coins;
    vector<int> dp;
    int solve(int  amount){
        if(amount<0) return INF; 
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int best = INF;
        for(auto& coin:coins){
            best = min(best,1+solve(amount-coin));
        }
        
        return dp[amount] = best;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(amount+1,-1);
        this->coins = coins;
        return solve(amount)==INF?-1:solve(amount);
    }
};