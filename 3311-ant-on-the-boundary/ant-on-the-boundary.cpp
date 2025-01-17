class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int totalSum = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            totalSum += nums[i];
            if(!totalSum) count++; 
        }
        return count;
    }
};