class Solution {
public:
    double gain(int p, int t) {
        return (double)(p + 1) / (t + 1) - (double)p / t;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;

        // Initialize heap
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();

            int p = top.second.first;
            int t = top.second.second;

            p++;
            t++;

            pq.push({gain(p, t), {p, t}});
        }

        // Compute final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top();
            pq.pop();
            sum += (double)pt.first / pt.second;
        }

        return sum / classes.size();

    }
};