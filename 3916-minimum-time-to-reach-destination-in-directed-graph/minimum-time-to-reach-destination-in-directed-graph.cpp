class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;

        // Graph: node -> list of {neighbor, {startTime, endTime}}
        unordered_map<int, vector<pair<int, pair<int, int>>>> mp;
        for (auto& it : edges) {
            mp[it[0]].push_back({it[1], {it[2], it[3]}});
        }

        // Min-heap: {current time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n, INT_MAX);

        // Start from node 0 at time 0
        pq.push({0, 0});

        while (!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Already visited with a better time
            if (t >= time[node]) continue;

            time[node] = t;

            for (auto& it : mp[node]) {
                int nxt = it.first;
                int st = it.second.first;
                int ed = it.second.second;

                int temp = t;
                if (temp > ed) continue;       // Edge not usable
                if (temp < st) temp = st;      // Wait until start time
                temp += 1;                     // Travel takes 1 unit time

                if (temp < time[nxt]) {
                    pq.push({temp, nxt});
                }
            }
        }

        return time[n - 1] == INT_MAX ? -1 : time[n - 1];
    }
};