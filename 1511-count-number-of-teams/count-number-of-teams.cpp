class Solution {
public:
    int solve(int i,int k,vector<int>& nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(i==n){
            return 0;
        }
        if(k==3) return 1;
        if(dp[i][k]!=-1) return dp[i][k];
      
        int include = 0;
        for(int cur=i+1;cur<n;cur++){
            if(nums[cur]>nums[i]){
                include+=solve(cur,k+1,nums,dp);
            }
        }
        return dp[i][k] = include;
    }
    int solve1(int i,int k,vector<int>& nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(i==n){
            return 0;
        }
        if(k==3) return 1;
        if(dp[i][k]!=-1) return dp[i][k];
      
        int include = 0;
        for(int cur=i+1;cur<n;cur++){
            if(nums[cur]<nums[i]){
                include+=solve1(cur,k+1,nums,dp);
            }
        }
        return dp[i][k] = include;
    }
   
    int numTeams(vector<int>& rating) {
        // there n soldiers they have unique rating 
        // we can choose 3 soldiers amongst them under the following rule
        int n = rating.size();

        int ans = 0;
        vector<vector<int>> increase(n+1,vector<int>(4,-1));
        vector<vector<int>> decrease(n+1,vector<int>(4,-1));
        for(int i = 0;i<n;i++){
            ans +=solve(i,1,rating,increase)+solve1(i,1,rating,decrease) ;
        }
       
        return ans;
    }
};