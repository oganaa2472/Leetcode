class Solution {
public:
     int n;
    vector<vector<int>> events;
    vector<int> dp;
    bool comp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    int lowerBound(int i) {
        int left = i + 1, right = n - 1, ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] >= events[i][1]) { 
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    int solve(int i ){
        if(i==n) return 0;
        if (dp[i] != -1) return dp[i];
        int exc = solve(i+1);
        int nextIndex = lowerBound(i); 
        int inc = events[i][2] + solve(nextIndex);
        return dp[i] = max(exc, inc);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        events.clear();
        for (int i = 0; i < n; i++) {
            events.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(events.begin(), events.end());
        dp.assign(n, -1);
        return solve(0);
    }
};