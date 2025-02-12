class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = nums[0];
        int n=nums.size();
        for(int i = 1;i<n;i++){
            if(start==0) return false;
            start = max(start-1,nums[i]);
        }
        return true;
    }
};