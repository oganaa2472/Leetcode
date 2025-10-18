class Solution {
public:
    vector<vector<int>> dp;
    int solve(int begin_stick,int end_stick,vector<int>& cuts,int left,int right){
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int cost = 1e9;
        for(int i = left;i<=right;i++){
            int left_cost = solve(begin_stick,cuts[i],cuts,left,i-1);
            int right_cost = solve(cuts[i],end_stick,cuts,i+1,right);
            int total = (end_stick-begin_stick)+left_cost+right_cost;
            cost = min(cost,total);
        }
        return dp[left][right] = cost;

    } 
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        dp.resize(101,vector<int>(101,-1));
        sort(cuts.begin(),cuts.end());
        return solve(0,n,cuts,0,m-1);
    }
};