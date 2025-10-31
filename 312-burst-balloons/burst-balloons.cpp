class Solution {
public:
    vector<vector<int>> dp;
    int solve(int left,int right,vector<int>& nums){
        if(left>right) return 0;
         if (dp[left][right] != -1) return dp[left][right];
        int ans = 0;
        for(int k = left;k<=right;k++){
            int cost = nums[left-1]*nums[k]*nums[right+1];
            int curLeft = solve(left,k-1,nums);
            int curRight = solve(k+1,right,nums);
            ans = max(cost+curLeft+curRight,ans);
        }
        return dp[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        dp.assign(n + 2, vector<int>(n + 2, -1));
        return solve(1,n-2,nums);
    }
};