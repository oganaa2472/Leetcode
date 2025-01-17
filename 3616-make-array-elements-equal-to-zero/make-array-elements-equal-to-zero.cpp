class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int preSum = 0, totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
               
                if (preSum == (totalSum - preSum)) {
                    count += 2; 
                } else if (preSum + 1 == (totalSum - preSum) || preSum - 1 == (totalSum - preSum)) {
                    count += 1; 
                }
            }

     
            preSum += nums[i];
        }

        return count;
    }
};