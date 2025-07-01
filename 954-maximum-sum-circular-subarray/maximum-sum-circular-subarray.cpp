class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
          int n = nums.size();
        int suff = nums[n - 1];
        
        vector<int> suffixSum(nums.size()+1,0);
        suffixSum[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suff = suff+nums[i];
            suffixSum[i] = max(suff,suffixSum[i+1]);
        }
        int prefix = 0;
        int kadane = 0;
        int circularSum = nums[0];
        int sum = nums[0];;
        for(int i = 0;i<n;i++ ){
            
            kadane = max(nums[i]+kadane,nums[i]);
            sum = max(sum,kadane);
            prefix = prefix+nums[i];
            circularSum = max(circularSum,prefix+suffixSum[i+1]);
        }
        
        return max(sum,circularSum);
    }
};