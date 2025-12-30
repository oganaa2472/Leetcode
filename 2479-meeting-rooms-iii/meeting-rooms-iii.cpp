class Solution {
public:
    int mostBooked(int rooms, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> busy;
        for (int i = 0; i < rooms; i++) available.push(i);

        vector<long long> count(rooms, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                busy.push({end, room});
                count[room]++;
            }else{
                auto [t, room] = busy.top(); busy.pop();
                long long duration = end - start;
                busy.push({t + duration, room});
                count[room]++;
            }
        }
          int ans = 0;
            for (int i = 1; i < rooms; i++) {
                if (count[i] > count[ans]) ans = i;
            }
            return ans;
    }
};