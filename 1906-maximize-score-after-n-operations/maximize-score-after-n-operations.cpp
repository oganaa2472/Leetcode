class Solution {
public:
    vector<vector<int>> gcdGrid;
    int n;
    vector<int> dp;

    int solve(int mask, int index) {
        if (mask == (1 << n) - 1) return 0; 
        
        if (dp[mask] != -1) return dp[mask];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (((mask & (1 << i)) == 0) && ((mask & (1 << j)) == 0)) {
                    int newMask = mask | (1 << i) | (1 << j);
                    ans = max(ans, index * gcdGrid[i][j] + solve(newMask, index + 1));
                }
            }
        }
        return dp[mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        gcdGrid.assign(n, vector<int>(n, 0)); 

      
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdGrid[i][j] = __gcd(nums[i], nums[j]);
            }
        }

        dp.assign(1 << n, -1);
        return solve(0, 1);
    }
};
