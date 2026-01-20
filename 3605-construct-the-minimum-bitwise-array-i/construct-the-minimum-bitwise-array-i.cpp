class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); 

    for (int i = 0; i < n; ++i) {
        int num = nums[i];

       
        for (int x = 0; x < num; ++x) {
            if ((x | (x + 1)) == num) {
                ans[i] = x;
                break;
            }
        }
    }

    return ans;
    }
};