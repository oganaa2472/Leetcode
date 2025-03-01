#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> digits;
    int dp[12][2][2];

    int digitDP(int pos, bool tight, bool started, string &N) {
        if (pos == N.size()) return started; // If number is formed, count it

        if (dp[pos][tight][started] != -1) return dp[pos][tight][started];

        int limit = tight ? (N[pos] - '0') : 9;
        int count = 0;

        if (!started) {
            // Option to skip leading zeros
            count += digitDP(pos + 1, false, false, N);
        }

        // Try placing each digit from our set
        for (int d : digits) {
            if (d > limit) break; // No need to check beyond the limit
            count += digitDP(pos + 1, tight && (d == limit), true, N);
        }

        return dp[pos][tight][started] = count;
    }

    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string num = to_string(N);
        digits.clear();
        memset(dp, -1, sizeof(dp));

        for (string &d : D) {
            digits.push_back(d[0] - '0');
        }
        sort(digits.begin(), digits.end());

        return digitDP(0, true, false, num);
    }
};

