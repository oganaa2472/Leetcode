class Solution {
public:
    vector<vector<int>> dp;
    vector<int> cuts;
    int solve(int left,int right){
        if(dp[left][right]!=-1) return dp[left][right];
        if(right-left==1) return 0;
        
        int ans = INT_MAX;
        for(int k = left+1;k<right;k++){
            int cost = solve(left,k) + solve(k,right) + cuts[right]-cuts[left];
            ans = min(ans,cost);
        }
        return dp[left][right] = ans;
        
    }
    int minCost(int n, vector<int>& cuts) {
        int m = n+2;
       
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.resize(102,vector<int>(m,-1));
        this->cuts=cuts;
        return solve(0,cuts.size()-1);
    }
};