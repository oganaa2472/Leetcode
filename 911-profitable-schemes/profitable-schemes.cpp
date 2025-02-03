#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    
    // dp[i][count][sum]: Ways to form schemes using first i crimes, `count` members, and at least `sum` profit.
    int solve(int i, int count, int sum, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp) {
        if (i == group.size()) {
            return (sum >= minProfit) ? 1 : 0;  
        }
        
        if (dp[i][count][sum] != -1) return dp[i][count][sum];

        
        int res = solve(i + 1, count, sum, minProfit, group, profit, dp) % mod;

        if (count + group[i] <= n) {
            res = (res + solve(i + 1, count + group[i], min(minProfit, sum + profit[i]), minProfit, group, profit, dp)) % mod;
        }
        return dp[i][count][sum] = res;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        this->n = n;
        int m = group.size();
        
        
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

        return solve(0, 0, 0, minProfit, group, profit, dp);
    }
};
