class Solution {
public:
    vector<vector<int>> dp;
    int n;
    vector<int> cost,time;
    int solve(int i,int rem){
        if (rem <= 0) {
            return 0;
        }
        if(i>=n) return 1e9+7;

        if(dp[i][rem]!=-1) return dp[i][rem];

        
      

        int min_cost = solve(i+1, rem-time[i]-1);
        if(min_cost!=1e9+7){
            min_cost += cost[i];
        }
      

        min_cost = min(min_cost, solve(i + 1, rem));
        

        return dp[i][rem] = min_cost;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        dp.resize(501,vector<int>(501,-1));
        this->cost = cost;
        this->time = time;
        return solve(0,n);
    }
};