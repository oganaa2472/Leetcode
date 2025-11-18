class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);  // Initialize all vertices as uncolored
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                queue<int> q;
                q.push(i);
                colors[i] = 0;  // Start coloring with 0
                
                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    
                    for (int neighbor : graph[current]) {
                        if (colors[neighbor] == -1) {
                            colors[neighbor] = 1 - colors[current];  // Assign opposite color
                            q.push(neighbor);
                        } else if (colors[neighbor] == colors[current]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};