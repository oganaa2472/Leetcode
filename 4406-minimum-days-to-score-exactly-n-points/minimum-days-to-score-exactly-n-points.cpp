#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int solve(int s) {
        if (s == 0) return 0;
        if (memo[s] != -1) return memo[s];

        int min_days = INT_MAX;

        // k урттай цуврал бүрийг шалгах (T_k <= s байх хүртэл)
        for (long long k = 1; ; ++k) {
            long long t_k = k * (k + 1) / 2;
            if (t_k > s) break;

            if (t_k == s) {
                min_days = min(min_days, (int)k);
            } else {
                int res = solve(s - t_k);
                if (res != INT_MAX) {
                    // k хоног + 1 хоног алгассан (skip) + үлдсэн оноог цуглуулсан хоногууд
                    min_days = min(min_days, (int)k + 1 + res);
                }
            }
        }

        return memo[s] = min_days;
    }

public:
    int minDays(int n) {
        memo.assign(n + 1, -1);
        return solve(n);
    }
};