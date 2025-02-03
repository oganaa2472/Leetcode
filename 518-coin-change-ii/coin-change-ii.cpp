class Solution {
public:
    vector<int> coins;
    vector<vector<int>> dp;

    int solve(int index,int amount){
        if(amount<0) return 0;
        if(amount==0) return 1;
        if(dp[amount][index]!=-1) return dp[amount][index];
        int answer = 0;
        for(int i = index;i<coins.size();i++){
            answer += solve(i,amount-coins[i]);
        }
        return dp[amount][index] = answer;
    }
    int change(int amount, vector<int>& coins) {
         dp.resize(amount+1,vector<int>(coins.size()+1,-1));
        this->coins = coins;
        
        return solve(0,amount);
    }
};