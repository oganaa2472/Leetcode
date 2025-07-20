class Solution {
public:
long long dp[65][2][65];
string binary;
set<int> validPopcounts;


    set<int> computeValidPopcounts(int k) {
        set<int> valid;
        for (int c = 1; c <= 64; ++c) {
            int x = c, depth = 0;
            while (x > 1) {
                x = __builtin_popcount(x);
                ++depth;
            }
            if (depth == k - 1) {
                valid.insert(c);
            }
        }
        return valid;
    }

    string toBinary(long long n) {
        string s = "";
        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    long long dfs(int pos, bool tight, int ones) {
        if (pos == binary.size()) {
            return validPopcounts.count(ones) ? 1 : 0;
        }

        if (dp[pos][tight][ones] != -1) return dp[pos][tight][ones];

        int limit = tight ? binary[pos] - '0' : 1;
        long long res = 0;
        for (int d = 0; d <= limit; ++d) {
            bool newTight = tight && (d == limit);
            res += dfs(pos + 1, newTight, ones + d);
        }

        return dp[pos][tight][ones] = res;
    }
    long long popcountDepth(long long n, int k) {
        if (k == 0) return 1;

        validPopcounts = computeValidPopcounts(k);
        if (validPopcounts.empty()) return 0;

        binary = toBinary(n);
        memset(dp, -1, sizeof(dp));
        long long result = dfs(0, true, 0);

        if (k == 1 && validPopcounts.count(1)) result -= 1;
        return result;
    }
};