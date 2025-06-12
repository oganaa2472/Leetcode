class Solution {
public:
    double solve(int i, int k, vector<vector<double>>& dp, vector<int>& nums) {
        int n = nums.size();
        if (k == 0 && i == n) return 0.0;             // used all groups and elements
        if (k == 0 || i == n) return -1e9;            // invalid
        if (dp[i][k] > -0.5) return dp[i][k];

        double sum = 0.0, mx = 0.0;
        for (int j = i; j <= n - k; ++j) {            // make sure enough elements left
            sum += nums[j];
            double avg = sum / (j - i + 1);
            mx = max(mx, avg + solve(j + 1, k - 1, dp, nums));
        }

        return dp[i][k] = mx;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1.0));
        return solve(0, k, dp, nums);
    }
};
