class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
       int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int bestSum = target; bestSum >= 0; --bestSum) {
            if (dp[bestSum]) {
                return totalSum - 2 * bestSum;
            }
        }
        return 0;
    }
};