class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                subordinates[manager[i]].push_back(i);
            }
        }
        
        queue<pair<int, int>> q;
        q.push({headID, 0});
        int maxTime = 0;
        
        // Begin BFS
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int currentId = current.first;
            int currentTime = current.second;
            maxTime = max(maxTime, currentTime);
            
            // Traverse subordinates
            for (int sub : subordinates[currentId]) {
                q.push({sub, currentTime + informTime[currentId]});
            }
        }
        return maxTime;
    }
};