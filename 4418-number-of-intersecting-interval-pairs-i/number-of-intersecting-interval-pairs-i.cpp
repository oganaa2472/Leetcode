class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> starts(n), ends(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        long long ans = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            // intervals whose end < current start
            // do NOT intersect current interval
            while (j < n && ends[j] < starts[i]) {
                j++;
            }

            // Among previous i intervals,
            // j of them ended before current start.
            ans += i - j;
        }

        return ans;
    }
};
