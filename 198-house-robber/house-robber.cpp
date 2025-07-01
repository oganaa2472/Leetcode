class Solution {
public:
    int rob1(vector<int>& nums,int i,vector<int>& memo){
        if(i<0) return 0;
        if(memo[i]!=-1) return memo[i];
        int ans = max(rob1(nums,i-2,memo)+nums[i],rob1(nums,i-1,memo));
        memo[i] = ans;
        return memo[i];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return rob1(nums,nums.size()-1,memo);
    }
};