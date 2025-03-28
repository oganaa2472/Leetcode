class Solution {
public:
    vector<int> dp;
    int target;
    int n ;
    vector<int> nums;
    bool solve(int mask,int cur,int k){
        if(k==0) return true;
        if(cur==0) return solve(mask,target,k-1);

        if(dp[mask]!=-1) return dp[mask];

        for(int i = 0;i<n;i++){
            if(!(mask&(1<<i))&&cur-nums[i]>=0){
                if(solve((mask|(1<<i)),cur-nums[i],k)){
                    return dp[mask] = true;
                }
            }
        }
        return dp[mask] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum%k!=0||nums.size()<k) return false;
        this->nums=nums;
        n = nums.size();
        target = sum/k;
        dp.resize((1<<n)+5,-1);

        return solve(0,target,k);
    }
};