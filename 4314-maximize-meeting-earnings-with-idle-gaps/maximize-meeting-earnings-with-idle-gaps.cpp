class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0];
             });

        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = meetings[i][0];
        }

        // dp[i]: i-р уулзалтыг заавал сонгосон
        // үед олох хамгийн их орлого
        vector<long long> dp(n);

        // suffix[i] = max(starts[k] + dp[k]), k >= i
        vector<long long> suffix(n + 1, LLONG_MIN);

        long long ans = LLONG_MIN;

        for (int i = n - 1; i >= 0; i--) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            long long revenue = meetings[i][2];

            // end[i]-ээс хойш эсвэл яг end[i]-д
            // эхлэх эхний уулзалтыг олно
            int j = lower_bound(
                starts.begin() + i + 1,
                starts.end(),
                end
            ) - starts.begin();

            // Дараагийн уулзалтыг сонгохгүй байж болно
            long long extra = 0;

            if (j < n) {
                extra = max(0LL, suffix[j] - end);
            }

            dp[i] = revenue + extra;

            suffix[i] = max(
                suffix[i + 1],
                (long long)start + dp[i]
            );

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};