class Solution {
public:
    
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, set<pair<int, int>> &s, int start) {
       
        visited[node] = true;

      
        if (start != -1) {
            s.insert({start, node});
        }

        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, s, start);
            }
        }
    }

   
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &pre, vector<vector<int>> &q) {
       
        vector<vector<int>> adj(n);
        for (const auto &p : pre) {
            adj[p[0]].push_back(p[1]); 
        }

       
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
           
            vector<bool> visited(n, false);
            dfs(i, adj, visited, s, i);    
        }

       
        vector<bool> result(q.size(), false); 
        for (int i = 0; i < q.size(); i++) {
          
            if (s.find({q[i][0], q[i][1]}) != s.end()) {
                result[i] = true; 
            }
        }

        return result;
    }
};