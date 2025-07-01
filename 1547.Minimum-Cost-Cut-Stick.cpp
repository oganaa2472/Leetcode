class Solution {
public:
    vector<vector<int>> dp;
    vector<int> cuts;
    int solve(int left,int right){
        if(right-left==1) return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int ans = INT_MAX;
        for(int k = left+1;k<right;k++){
            int cost = solve(left,k) + solve(k,right) + cuts[right]-cuts[left];
            ans = min(ans,cost);
        }
        return dp[left][right] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        this->cuts = cuts;
        dp.resize(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(0,cuts.size()-1);
    }
};
