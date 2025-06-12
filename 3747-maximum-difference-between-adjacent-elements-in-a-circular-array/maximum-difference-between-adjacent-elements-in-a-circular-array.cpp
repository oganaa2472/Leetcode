class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
         int ans = INT_MIN;
        int n = nums.size();
        for(int i = 1;i<nums.size();i++){
            ans=max(ans,abs(nums[i]-nums[i-1]));
        }
        ans = max(ans,abs(nums[0]-nums[n-1]));
        return ans;
    }
};