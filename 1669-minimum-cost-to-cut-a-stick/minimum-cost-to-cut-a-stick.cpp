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
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));

        int m = cuts.size(); // Correct m size
        this->cuts = cuts;
        dp.resize(m, vector<int>(m, -1));

        return solve(0, m - 1);
    }
};