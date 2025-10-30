class Solution {
public:
    
     vector<vector<vector<int>>> dp;
    int solve(int left, int right, int k, string &s) {
        if (left > right) return 0;
        if (left == right) return 1;

       if(dp[left][right][k]!=-1) return dp[left][right][k];

        int f1 = solve(left + 1, right, k, s);
        int f2 = solve(left, right - 1, k, s);
        int inc = 0;

        if (s[left] == s[right]) {
            inc = solve(left + 1, right - 1, k, s) + 2;
        } else {
            int diff = abs((s[left] - s[right] + 26) % 26);
            int count = min(diff, 26 - diff);
            if (count <= k)
                inc = solve(left + 1, right - 1, k - count, s) + 2;
        }

        return dp[left][right][k] = max({f1, f2, inc});
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(0, s.size() - 1, k, s);
    }
};
