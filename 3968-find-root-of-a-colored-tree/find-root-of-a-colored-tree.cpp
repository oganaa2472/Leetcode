class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> c(n);

        for (int i = 0; i < n; i++) {
            if (colors[i] == 'R') c[i] = 0;
            else if (colors[i] == 'B') c[i] = 1;
            else c[i] = 2;
        }

        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (c[u] == c[v]) return -1;

            if ((c[u] + 1) % 3 == c[v]) {
                outdegree[u]++;
                indegree[v]++;
            } else {
                outdegree[v]++;
                indegree[u]++;
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) return -1;
                root = i;
            }

            if (indegree[i] > 1) return -1;
            if (outdegree[i] > 2) return -1;
        }

        return root;
    }
};