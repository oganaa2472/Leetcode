
class Solution {
public:
    using ll = long long;
    using pll = pair<ll, ll>;

    const ll MOD1 = 1e9 + 7;
    const ll MOD2 = 1e9 + 9;
    const ll BASE = 911382323;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ll> p1(n + 1, 1), p2(n + 1, 1);
        vector<ll> h1(n + 1, 0), h2(n + 1, 0);

        // Precompute powers and prefix hashes
        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            ll x1 = ((ll)nums[i] % MOD1 + MOD1) % MOD1;
            ll x2 = ((ll)nums[i] % MOD2 + MOD2) % MOD2;

            h1[i + 1] = (h1[i] * BASE + x1 + 1) % MOD1;
            h2[i + 1] = (h2[i] * BASE + x2 + 1) % MOD2;
        }

        auto check = [&](int len) -> bool {
            map<pll, int> freq;

            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                ll hash1 = (h1[j] -
                    h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

                ll hash2 = (h2[j] -
                    h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                pll key = {hash1, hash2};

                freq[key]++;
            }

            for (auto &[key, count] : freq) {
                if (count == 1) {
                    return true;
                }
            }

            return false;
        };

        int left = 1;
        int right = n;
        int ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
