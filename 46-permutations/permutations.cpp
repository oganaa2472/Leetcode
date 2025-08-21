class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, vector<int>& nums,vector<int>& ans){
        int n = nums.size();
        if(i==n){
            result.push_back(ans);
            return;
        }
        for(int j = 0;j<n;j++){
            auto it = find(ans.begin(), ans.end(),nums[j]);
            if(it==ans.end()){
                ans.push_back(nums[j]);
                solve(i+1,nums,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        solve(0,nums,ans);
        return result;
    }
};