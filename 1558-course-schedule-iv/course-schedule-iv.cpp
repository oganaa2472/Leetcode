class Solution {
public:
    unordered_set<int> dfs(int crs, unordered_map<int, vector<int>>& adj, unordered_map<int, unordered_set<int>>& prereqMap) {
    if (prereqMap.find(crs) == prereqMap.end()) {
        prereqMap[crs] = unordered_set<int>();
        for (int prereq : adj[crs]) {
            auto prereqSet = dfs(prereq, adj, prereqMap);
            prereqMap[crs].insert(prereqSet.begin(), prereqSet.end());
        }
        prereqMap[crs].insert(crs); 
    }
    return prereqMap[crs];
}

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (const auto& pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]);
        }

        unordered_map<int, unordered_set<int>> prereqMap;

        for (int crs = 0; crs < numCourses; ++crs) {
            dfs(crs, adj, prereqMap);
        }
        vector<bool> res;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            res.push_back(prereqMap[v].count(u) > 0);
        }

        return res;
    }
};