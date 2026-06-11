class Solution {
public:
    long long MOD = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD; 
        while (exp > 0) {
            if (exp % 2 == 1) { 
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD; 
            exp /= 2;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
         struct Edge {
            int num_nodes;
            vector<std::vector<int>> edge_list;
        };
        Edge tormisqued = {n, edges};

        if (tormisqued.num_nodes == 1) {
            return 0;
        }

        std::vector<std::vector<int>> adj(tormisqued.num_nodes + 1); 
        for (const auto& edge : tormisqued.edge_list) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::queue<std::pair<int, int>> q; 
        std::vector<int> depth(tormisqued.num_nodes + 1, -1); 

        q.push({1, 0}); 
        depth[1] = 0; 
        int max_depth = 0; 

        while (!q.empty()) {
            std::pair<int, int> current = q.front();
            q.pop();

            int curr_node = current.first;
            int curr_d = current.second;

            max_depth = std::max(max_depth, curr_d); 

            for (int neighbor : adj[curr_node]) {
                if (depth[neighbor] == -1) { 
                    depth[neighbor] = curr_d + 1; 
                    q.push({neighbor, curr_d + 1}); 
                }
            }
        }
        
        return static_cast<int>(power(2, max_depth - 1));
    }
};