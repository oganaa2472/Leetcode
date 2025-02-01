class Solution {
public:
    int n;
    int target;
    unordered_map<int,unordered_map<int,int>> dp;
    int solve(int i,int sum, vector<int>&nums){
        if(i==n){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum]!=0){
            return dp[i][sum];   
        }
        int include = solve(i+1,sum+nums[i],nums);
        int exclude = solve(i+1,sum-nums[i],nums);

        return dp[i][sum] = include+exclude;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        n=nums.size();
        this->target=target;
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int answer = solve(0,0,nums);
        return answer;
    }
};