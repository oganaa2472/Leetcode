class Solution {
public:
    int dp[100001][3][3];
    int mod = 1e9 + 7;

    int solve(int index, int prev, int lastprev, vector<int>& nums) {
        if (index == nums.size()) {
            if (prev == -1 && lastprev == -1) return 0; // empty subsequence
            return 1; // valid subsequence
        }

        if (dp[index][prev + 1][lastprev + 1] != -1) 
            return dp[index][prev + 1][lastprev + 1];

        // Option 1: not pick current element
        int notpick = solve(index + 1, prev, lastprev, nums) % mod;

        // Option 2: pick current element
        int pick = 0;
        if (lastprev == -1 && prev == -1) {
            // no element chosen yet
            pick = solve(index + 1, nums[index], lastprev, nums) % mod;
        } else if (lastprev == -1) {
            // only one element chosen
            pick = solve(index + 1, nums[index], prev, nums) % mod;
        } else {
            // at least 2 elements chosen, check constraint
            if (!(prev == lastprev && prev == nums[index])) {
                pick = solve(index + 1, nums[index], prev, nums) % mod;
            }
        }

        return dp[index][prev + 1][lastprev + 1] = (pick + notpick) % mod;
    }

    int countStableSubsequences(vector<int>& nums) {
        vector<int> update;
        for (int i = 0; i < nums.size(); i++) {
            update.push_back(nums[i] % 2); // reduce to parity
        }

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, -1, -1, update);
        return ans % mod;
    }
};
