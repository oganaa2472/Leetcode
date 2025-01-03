class Solution {
public:
    void solve(int k,vector<vector<int>>& answer,vector<int>&nums,vector<int>& subset) {
    if (k == nums.size()) {
        answer.push_back(subset);
        return;
    } else {
            solve(k+1,answer,nums,subset);
            subset.push_back(nums[k]);
            solve(k+1,answer,nums,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0,ans,nums,subset);
        return ans;
    }
};