class Solution {
public:
    int binarysearch(vector<vector<int>>& meetings, int end) {
        int l = 0, r = meetings.size() - 1;
        int ans = meetings.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (meetings[m][0] >= end) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    long long maxEarnings(vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            const auto& meet = meetings[i];

            long long skip = dp[i + 1];

            int idx = binarysearch(meetings, meet[1]);

            long long last = meet[0] + meet[2];
            long long intermediate = last - meet[1] + dp[idx];

            long long take = max(last, intermediate);
            dp[i] = max(take, skip);
        }

        long long mx = 0;
        for (int i = 0; i < n; i++) {
            int idx = binarysearch(meetings, meetings[i][1]);
            long long curr = meetings[i][2];
            
            mx = max(mx, curr);
            mx = max(mx, curr - meetings[i][1] + dp[idx]);
        }

        return mx;
    }
};