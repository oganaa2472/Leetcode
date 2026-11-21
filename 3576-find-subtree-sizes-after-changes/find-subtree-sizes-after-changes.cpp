
class Solution {
public:
    vector<int> findSubtreeSizes(
        vector<int>& parent,
        string s
    ) {
        int n = parent.size();

        vector<vector<int>> children(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        // Step 1: Find new parent using DFS
        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            int old = last[c];

            if (old != -1) {
                newParent[u] = old;
            } else {
                newParent[u] = parent[u];
            }

            last[c] = u;

            for (int v : children[u]) {
                dfs(v);
            }

            // Backtracking
            last[c] = old;
        };

        dfs(0);

        // Step 2: Build final tree
        vector<vector<int>> finalTree(n);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        // Step 3: Calculate subtree sizes
        vector<int> answer(n, 1);

        function<int(int)> calculate = [&](int u) {
            for (int v : finalTree[u]) {
                answer[u] += calculate(v);
            }

            return answer[u];
        };

        calculate(0);

        return answer;
    }
};
