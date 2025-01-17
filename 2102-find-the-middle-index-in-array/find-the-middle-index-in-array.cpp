class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            totalSum += nums[i];
        }
        int preSum = 0;

        for(int i = 0;i<n;i++){

            if(preSum==(totalSum-nums[i])) return i;
            preSum += nums[i];
            totalSum-=nums[i];
        }
        return -1;
    }
};