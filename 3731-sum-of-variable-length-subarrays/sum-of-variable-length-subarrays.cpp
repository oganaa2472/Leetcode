class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);

      
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        long long totalSum = 0;

        
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            totalSum += prefixSum[i + 1] - prefixSum[start];
        }

        return totalSum;
    }
};