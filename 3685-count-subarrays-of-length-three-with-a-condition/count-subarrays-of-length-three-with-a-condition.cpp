class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 1;i<n-1;i++){
            count+=nums[i] == (nums[i-1]+nums[i+1])*2?1:0;
        }
        return count;
    }
};