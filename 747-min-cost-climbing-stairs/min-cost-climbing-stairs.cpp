#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& cost) {
        if (i >= cost.size()) return 0; 
        if (dp[i] != -1) return dp[i]; 
        return dp[i] = cost[i] + min(solve(i + 1, cost), solve(i + 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n, -1); 

       
        return min(solve(0, cost), solve(1, cost));
    }
};
