class Solution {
public:
    int n;
    vector<int> sum;
    vector<vector<int>> memo;

    int dfs(int mask, int k) {
        if (k == 1) return sum[mask]; // last child gets all remaining bags
        if (memo[k][mask] != -1) return memo[k][mask];

        int res = INT_MAX;
        // iterate over all non-empty submasks
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            int unfair = max(sum[sub], dfs(mask ^ sub, k - 1));
            res = min(res, unfair);
        }
        return memo[k][mask] = res;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        int full = 1 << n;
        sum.assign(full, 0);

        // Precompute sum of each subset
        for (int mask = 0; mask < full; ++mask)
            for (int i = 0; i < n; ++i)
                if (mask & (1 << i)) sum[mask] += cookies[i];

        memo.assign(k + 1, vector<int>(full, -1));
        return dfs(full - 1, k);
    }
};
