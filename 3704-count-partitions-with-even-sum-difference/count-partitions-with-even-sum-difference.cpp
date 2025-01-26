class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; 
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) {
            return 0;
        }

       
        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            int rightSum = totalSum - prefixSum;
            if ((prefixSum - rightSum) % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};