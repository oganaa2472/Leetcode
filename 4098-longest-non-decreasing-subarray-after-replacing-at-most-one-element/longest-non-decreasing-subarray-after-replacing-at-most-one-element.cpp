class Solution {
public:
    int rep(int i,int taken,int replaced,int replacedRecently,int takenLast,int n,vector<int>& nums,vector<vector<vector<vector<vector<int>>>>>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[taken][replaced][replacedRecently][takenLast][i] != -1){
            return dp[taken][replaced][replacedRecently][takenLast][i];
        }
        int ans = 0;
        if(taken){
            if((i == 0 || (nums[i-1] <= nums[i] && !replacedRecently))){
                ans = max(ans,1 + rep(i+1,taken,replaced,replacedRecently,0,n,nums,dp));
            }
            if(!replaced){
                ans = max(ans,1 + rep(i+1,taken,1,1,0,n,nums,dp));
            }
            if(replacedRecently && (i <= 1 || (nums[i] >= nums[i-2] || takenLast))){
                ans = max(ans,1 + rep(i+1,taken,1,0,0,n,nums,dp));
            }
        }
        else{
            ans = max(ans,1 + rep(i+1,1,replaced,replacedRecently,1,n,nums,dp));
            ans = max(ans,rep(i+1,taken,replaced,replacedRecently,takenLast,n,nums,dp));
            if(!replaced){
                ans = max(ans,1 + rep(i+1,1,1,1,1,n,nums,dp));
            }
        }
        return dp[taken][replaced][replacedRecently][takenLast][i] = ans;
    }
    
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<vector<vector<int>>>>> dp(2,vector<vector<vector<vector<int>>>>(2,vector<vector<vector<int>>>(2,vector<vector<int>>(2,vector<int>(n,-1)))));
        return rep(0,0,0,0,0,n,nums,dp);
        
    }
};