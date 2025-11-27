class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n+1,0);
         for(int i = 0;i<n;i++){
             prefixSum[i+1] = prefixSum[i]+nums[i];
         }   
        unordered_map<int,long long> mp;
        long long maxSum = LLONG_MIN;
        for(int i = 0;i<=n;i++){
            int rem = i%k;
            if(mp.find(rem)!=mp.end()){
                maxSum = max(maxSum,prefixSum[i]-mp[rem]);
            }
            if(mp.find(rem)==mp.end()){
                mp[rem] = prefixSum[i];
            }else{
                mp[rem] = min(prefixSum[i],mp[rem]);
            }
            
        }
        return maxSum == LLONG_MIN?-1:maxSum;
    } 
};