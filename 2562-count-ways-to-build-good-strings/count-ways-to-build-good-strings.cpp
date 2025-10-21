class Solution {
public:
    const int MOD = 1e9 + 7;
    int zeroLen, oneLen;
    vector<int> memo;

    int dfs(int i, int low, int high) {
        if (i > high) return 0;
        if (memo[i] != -1) return memo[i];

        long long res = 0;
        if (i >= low && i <= high) res = 1;  // count this valid length

        res = (res + dfs(i + zeroLen, low, high)) % MOD;
        res = (res + dfs(i + oneLen, low, high)) % MOD;

        return memo[i] = res;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        zeroLen = zero;
        oneLen = one;
        memo.assign(high + 1, -1);
        return dfs(0, low, high);
    }
};
