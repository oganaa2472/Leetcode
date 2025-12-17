
class Solution {
public:
    long long solve(int i,int k,int type,vector<vector<vector<long long>>>& dp,vector<int>& prices){
        if(i==prices.size()){
            return type==0?0:-1e12;
        }
        if(dp[i][type][k]!=-1) return dp[i][type][k];
        long long skip = solve(i+1,k,type,dp,prices);
        long long res = 0;
        if(type==0){
            if(k>0){
                long long buyNormal = -prices[i] + solve(i+1,k,1,dp,prices);
                long long shortSell = prices[i] + solve(i+1,k,2,dp,prices);
                res = max({skip,buyNormal,shortSell});
            }else{
                res = skip;
            }
        }else if(type==1){
            long long sell = prices[i] + solve(i+1,k-1,0,dp,prices);
            res = max(skip,sell);
        }else{
             long long buyBack = -prices[i] + solve(i+1,k-1,0,dp,prices);
             res = max(skip,buyBack);
        
        }
        return dp[i][type][k] = res;
    }  

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) {
            return 0;
        }
        int types = 3 ;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(types, vector<long long>(k + 1, -1)));

        return solve(0,k,0,dp,prices);
    }
};