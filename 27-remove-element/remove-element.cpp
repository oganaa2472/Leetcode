class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int count =0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(nums[i]==val) count++;
            else ans.push_back(nums[i]);
        }
        nums = ans;
        return n - count;
    }
};