class Solution {
public:
    vector<vector<int>> memo;
    
    int dfs(int i, int j, vector<int>& nums) {
        if (i == nums.size()) {
            return 0;
        }
        if (memo[i][j + 1] != -1) {  
            return memo[i][j + 1];
        }

        int LIS = dfs(i + 1, j, nums);

        if (j == -1 || nums[j] < nums[i]) {
            LIS = max(LIS, 1 + dfs(i + 1, i, nums));
        }

        memo[i][j + 1] = LIS;
        return LIS;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(n + 1, -1)); 
        return dfs(0, -1, nums);
    }
};