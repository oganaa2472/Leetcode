class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = nums.size()+1;
        while(left<nums.size()){
        
            while(sum<target&&right<nums.size()){
                sum = sum + nums[right];
                right++;
            }
            if(sum>=target)
                ans = min(right-left,ans);
            sum=sum-nums[left];
          
            left++;
            
        }
        return ans == nums.size()+1 ? 0:ans;
    }
};