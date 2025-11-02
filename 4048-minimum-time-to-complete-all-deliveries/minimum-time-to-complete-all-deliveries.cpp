#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    bool canComplete(long long T, long long d1, long long d2, long long r1, long long r2) {
        long long work1 = T - T / r1;
        long long work2 = T - T / r2;

        // Each drone must have enough time
        if (work1 < d1 || work2 < d2) return false;
        long long lcm = (1LL * r1 * r2) / gcd(r1, r2);
        long long total = T - T / lcm;
        // Total deliveries cannot exceed total available hours
        return (d1 + d2) <= total;
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long lo = 0, hi = 1e18, ans = -1;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (canComplete(mid, d[0], d[1], r[0], r[1])) {
                ans = mid;
                hi = mid - 1; // try smaller time
            } else {
                lo = mid + 1; // need more time
            }
        }

        return ans;
    }
};
