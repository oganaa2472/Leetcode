class Solution {
public:
    int target;
    unordered_map<int, bool> dp;

    bool solve(vector<int>& nums, int k, int usedMask, int currentSum, int count) {
      if(k-1==count) return true;
      if(dp.count(usedMask)) return dp[usedMask];

      if(currentSum==target){
        return dp[usedMask] = solve(nums,k,usedMask,0,count+1);
      }
      for(int i = 0;i<nums.size();i++){
        if(!(usedMask & (1 << i))&&currentSum + nums[i] <= target){
            if(solve(nums,k, usedMask | (1 << i),currentSum + nums[i], count)){
                return dp[usedMask] = true;
            }
        }
      }
      return dp[usedMask] = false; 
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        target = sum / k;
      

        return solve(nums, k, 0, 0, 0);
    }
};
