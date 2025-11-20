class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        // Map to track which bus routes are available for each stop
        unordered_map<int, vector<int>> stopToRoutesMap;
        
        // Fill the map with stop to routes associations
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutesMap[stop].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        // Track visited routes to avoid cycles
        vector<bool> visited(routes.size(), false);
        
        // Add all routes starting with the source stop
        for (int route : stopToRoutesMap[source]) {
            q.push({route, 1});
            visited[route] = true;
        }
         while (!q.empty()) {
            auto [routeIndex, busesTaken] = q.front();
            q.pop();
             for (int stop : routes[routeIndex]) {
                // Check if we've reached the target
                if (stop == target) return busesTaken;
                
                // Check all neighboring routes of the current stop
                for (int nextRoute : stopToRoutesMap[stop]) {
                    if (!visited[nextRoute]) {
                        q.push({nextRoute, busesTaken + 1});
                        visited[nextRoute] = true;
                    }
                }
            }
        }
        return -1;
    }
};