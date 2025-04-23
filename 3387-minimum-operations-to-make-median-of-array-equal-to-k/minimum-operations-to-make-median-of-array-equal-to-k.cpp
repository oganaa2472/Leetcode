class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long n = nums.size();
        long long ans = 0;
        // 4 / 2 = 2 0 1 2 3
        // 5/2  = 2 
        long long mid = n/2;
        for(int i = 0;i<=mid;i++){
            if(nums[i]>k){
                ans +=nums[i]-k;
            }
        }
        for(int i = mid;i<n;i++){
            if(nums[i]<k){
                ans +=k-nums[i];
            }
        }
    
        return ans;
    }
};