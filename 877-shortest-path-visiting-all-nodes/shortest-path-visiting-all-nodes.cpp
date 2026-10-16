class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
    if (n == 1) return 0;

    int full_mask = (1 << n) - 1; // Бүх зангилааг зочилсон үеийн маск (жишээ нь n=3 үед 111 буюу 7)
    
    // visited[node][mask] : Тухайн node дээр тухайн mask-тай төлөвтэй зочилсон эсэх
    vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
    
    // Queue хадгалах хэлбэр: {node, mask, dist}
    queue<tuple<int, int, int>> q;

    // Дурын зангилаанаас эхэлж болох тул бүх зангилааг эхлэх цэгээр оруулна
    for (int i = 0; i < n; ++i) {
        int initial_mask = 1 << i;
        q.push({i, initial_mask, 0});
        visited[i][initial_mask] = true;
    }

    while (!q.empty()) {
        auto [node, mask, dist] = q.front();
        q.pop();

        // Хэрэв бүх зангилааг зочилсон бол хамгийн анхны тул энэ нь хамгийн богино зам мөн
        if (mask == full_mask) {
            return dist;
        }

        // Хөрш зангилаанууд руу шилжих
        for (int neighbor : graph[node]) {
            int next_mask = mask | (1 << neighbor);

            if (!visited[neighbor][next_mask]) {
                visited[neighbor][next_mask] = true;
                q.push({neighbor, next_mask, dist + 1});
            }
        }
    }

    return 0;

    }
};