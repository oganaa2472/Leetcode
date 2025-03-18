class Solution {
public:
    bool isAllStars(string &S1, int i) {
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0) return true;  // Both strings are empty
        if (i < 0 && j >= 0) return false; // Pattern is exhausted, but text remains
        if (j < 0 && i >= 0) return isAllStars(S1, i); // If pattern is '*', it can match empty string

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        if (S1[i] == S2[j] || S1[i] == '?') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
        }

        if (S1[i] == '*') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string S2, string S1) {
        int n = S1.size();
        int m = S2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1)); // Use int instead of bool
        return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
    }
};