class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> answer(nums.size());
        int n = nums.size();
        for(int i = 0;i<n;i++){
           answer[(i+k)%n] = nums[i]; 
        }
        nums = answer;
    }
};