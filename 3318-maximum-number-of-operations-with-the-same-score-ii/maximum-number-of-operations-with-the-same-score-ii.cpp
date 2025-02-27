class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    
    int solve(int i, int j, int sum) {
        if (i > j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        if (sum == 0) {
            int a = (j - 1 >= i) ? solve(i, j - 2, nums[j] + nums[j - 1]) + 1 : 0;
            int b = (i + 1 <= j) ? solve(i + 2, j, nums[i] + nums[i + 1]) + 1 : 0;
            int c = (i < j) ? solve(i + 1, j - 1, nums[i] + nums[j]) + 1 : 0;
            return dp[i][j] = max({a, b, c});
        }

        int mx = 0;
        if (j - 1 >= i && nums[j] + nums[j - 1] == sum) {
            mx = max(mx, 1 + solve(i, j - 2, sum));
        }
        if (i + 1 <= j && nums[i] + nums[i + 1] == sum) {
            mx = max(mx, 1 + solve(i + 2, j, sum));
        }
        if (i < j && nums[i] + nums[j] == sum) {
            mx = max(mx, 1 + solve(i + 1, j - 1, sum));
        }

        return dp[i][j] = mx;
    }
    
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        
        dp.resize(n, vector<int>(n, -1)); 

        return solve(0, n - 1, 0);
    }
};
