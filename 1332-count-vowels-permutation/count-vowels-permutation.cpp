class Solution {
public:
    int mod = 1e9+7;
    vector<int> number = {0,1,2,3,4};
    vector<vector<int>> dp;
    int n;

    int solve(int i, int last) {
        if (i == n) {
            return 1;  // Base case should return 1 (counting valid sequences)
        }
        if (dp[i][last] != -1) return dp[i][last];

        int ans = 0;

        if (i == 0) {
            // Iterate over all possible starting vowels
            for (int k = 0; k < number.size(); k++) {
                ans = (ans + solve(i + 1, number[k])) % mod;
            }
        } else {
            // Transition rules based on the last vowel used
            if (last == 0) { // 'a' -> 'e'
                ans = (ans + solve(i + 1, 1)) % mod;
            } else if (last == 1) { // 'e' -> 'a' or 'i'
                ans = (ans + solve(i + 1, 0)) % mod;
                ans = (ans + solve(i + 1, 2)) % mod;
            } else if (last == 2) { // 'i' -> 'a', 'e', 'o', 'u'
                ans = (ans + solve(i + 1, 0)) % mod;
                ans = (ans + solve(i + 1, 1)) % mod;
                ans = (ans + solve(i + 1, 3)) % mod;
                ans = (ans + solve(i + 1, 4)) % mod;
            } else if (last == 3) { // 'o' -> 'i' or 'u'
                ans = (ans + solve(i + 1, 2)) % mod;
                ans = (ans + solve(i + 1, 4)) % mod;
            } else if (last == 4) { // 'u' -> 'a'
                ans = (ans + solve(i + 1, 0)) % mod;
            }
        }
        return dp[i][last] = ans;
    }

    int countVowelPermutation(int n) {
        dp.resize(n, vector<int>(5, -1)); // Correctly resize dp for `n x 5`
        this->n = n;
        return solve(0, 0); // Start with index 0
    }
};
