#include <vector>
#include <queue>
#include <cmath> // For std::sqrt, though comparing squared distance is sufficient
#include <vector> // Included for std::vector

// Custom comparator struct for the priority queue.
// We want a max-heap based on the distance from the origin.
// The comparator defines the order such that the element with the *larger* distance
// has higher priority (sits at the top of the max-heap).
// The operator() should return true if the first argument has *lower* priority than the second.
struct CompareDistance {
    bool operator()(const std::vector<int>& p1, const std::vector<int>& p2) const {
        // Calculate the squared Euclidean distance from the origin (0, 0).
        // Using squared distance avoids using std::sqrt and potential floating-point issues,
        // and comparing squared distances is equivalent to comparing distances.
        // Use long long for the calculation to prevent potential integer overflow
        // if the coordinate values are large.
        long long dist1_sq = (long long)p1[0] * p1[0] + (long long)p1[1] * p1[1];
        long long dist2_sq = (long long)p2[0] * p2[0] + (long long)p2[1] * p2[1];

        // For a max-heap of distances, p1 has lower priority than p2 if p1 is *closer* to the origin.
        // So, return true if dist1_sq is less than dist2_sq.
        return dist1_sq < dist2_sq;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int K) {
        // Use a priority queue (max-heap by default) to keep track of the K closest points.
        // We use a max-heap of distances. The heap will store up to K points.
        // The point with the largest distance among the K will be at the top.
        // This allows us to efficiently remove the farthest point when we add a closer one.
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, CompareDistance> pq;

        // Iterate through each point in the input vector.
        for (const auto& p : points) {
            // Add the current point to the priority queue.
            pq.push(p);

            // If the number of points in the priority queue exceeds K,
            // remove the point with the largest distance (which is at the top of the max-heap).
            if (pq.size() > K) {
                pq.pop();
            }
        }

        // After iterating through all points, the priority queue contains the K points
        // with the smallest distances from the origin.
        // Now, extract these K points into the result vector.
        std::vector<std::vector<int>> res(K, std::vector<int>(2));
        int index = K - 1; // Start filling the result vector from the end (like the Java code)

        // While the priority queue is not empty, extract elements.
        // Since it's a max-heap of distances, we extract points in decreasing order of distance.
        // By filling the result vector from the end, the points will end up in ascending
        // order of distance (or an arbitrary order if distances are equal), but the problem
        // only requires the set of K closest points, order doesn't strictly matter.
        while (!pq.empty()) {
            res[index--] = pq.top(); // Get the point with the current largest distance in the heap
            pq.pop();              // Remove that point from the heap
        }

        return res; // Return the vector containing the K closest points
    }
};