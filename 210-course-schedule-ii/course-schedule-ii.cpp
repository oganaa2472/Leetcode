class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // Array to track indegrees of each node
        vector<int> indegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }
        queue<int> q; // Queue of courses with zero in-degree
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return (order.size() == numCourses) ? order : vector<int>{};

    }
};