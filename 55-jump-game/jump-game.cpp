class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(start==0) return false;
            start--;
            start = max(start,nums[i]);
        }
        return true;
    }
};