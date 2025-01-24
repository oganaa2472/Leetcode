class Solution {
public:
    int trap(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while(left<right){
            if(nums[left]<nums[right]){
                leftMax=max(leftMax,nums[left]);
                ans=ans+(leftMax-nums[left]);
                left++;
            }else{
                rightMax = max(rightMax,nums[right]);
                ans=ans+(rightMax-nums[right]);
                right--;
            }
        }
        return ans;
    }
};