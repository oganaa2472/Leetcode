#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return n * (n-1) / 2; // since r=2 always in this problem
}



    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        ans += nCr(n+2, 2);
        ans -= 3 * nCr(n - (limit+1) + 2, 2);
        ans += 3 * nCr(n - 2*(limit+1) + 2, 2);
        ans -= nCr(n - 3*(limit+1) + 2, 2);
        return ans;
    }
};