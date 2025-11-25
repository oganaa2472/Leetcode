class Solution {
private:
    struct Pair {
        double ratio;
        int quality;
        
        Pair(double r, int q) : ratio(r), quality(q) {}
    };

public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<Pair> workers;
        for (int i = 0; i < n; i++) {
            workers.push_back(Pair((double)wage[i] / quality[i], quality[i]));
        }
         // Sort workers by wage/quality ratio
        sort(workers.begin(), workers.end(), [](const Pair& a, const Pair& b) {
            return a.ratio < b.ratio;
        });
        double minCost = DBL_MAX;
        priority_queue<int> maxHeap;
        double sumQuality = 0;
        for (const Pair& worker : workers) {
            maxHeap.push(worker.quality);
            sumQuality += worker.quality;
            if (maxHeap.size() > k) {
                sumQuality -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                minCost = min(minCost, sumQuality * worker.ratio);
            }
        }
        return minCost;
    }
};