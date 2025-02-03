class Solution {
public:
    vector<int> nums;
    vector<int> dp;
    int solve(int target){
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int answer = 0;
        for(int i = 0;i<nums.size();i++){
            answer+=solve(target-nums[i]);
        }
        return dp[target] =  answer;
    }
    int combinationSum4(vector<int>& nums, int target) {
        this->nums = nums;
        dp.resize(target+1,-1);
        int answer = solve(target);
        return answer;
    }
};