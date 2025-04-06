class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        while (!isNonDecreasing(nums)) {
            int minSum = nums[0] + nums[1];
            int idx = 0;

            for (int i = 1; i < nums.size() - 1; i++) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }
        return operations;
    }
};