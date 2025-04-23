#include <vector>
#include <queue>
#include <limits> // For INT_MAX
#include <utility> // For std::pair

class Solution {
public:
    // Function to find the minimum time to reach each node, considering disappear times.
    // This is an adapted version of Dijkstra's algorithm.
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // Adjacency list to represent the graph.
        // Each entry adj[u] is a vector of pairs {v, weight}, representing an edge from u to v with given weight.
        // The graph is undirected, so we add edges in both directions.
        vector<vector<pair<int, int>>> adj(n);

        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight}); // Add reverse edge for undirected graph
        }

        // Distance vector: stores the shortest time (distance) found so far from the source (node 0)
        // to each node. Initialize all distances to infinity except the source.
        vector<int> dist(n, numeric_limits<int>::max());
        dist[0] = 0; // Source node (node 0) has a distance of 0

        // Priority queue: stores pairs of {time, vertex}.
        // It's a min-priority queue, so the element with the smallest time is at the top.
        // We use std::greater to make it a min-priority queue based on the 'time' (first element).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Push the source vertex (0) with time 0 into the priority queue.
        pq.push({0, 0});

        // Main loop of Dijkstra's algorithm
        while (!pq.empty()) {
            // Extract the vertex with the minimum time from the priority queue.
            pair<int, int> current = pq.top();
            pq.pop();

            int u = current.second; // The current vertex
            int d = current.first; // The time (distance) to the current vertex

            // If the extracted time 'd' is greater than the current recorded distance for u,
            // it means we have already found a shorter path to u and processed it.
            // Also, if the current time 'd' is greater than or equal to the disappear time
            // for this node, we cannot proceed from this node.
            if (d > dist[u] || d >= disappear[u]) {
                continue;
            }

            // Iterate through all neighbors of the current vertex u
            for (const auto& edge : adj[u]) {
                int v = edge.first; // The neighbor vertex
                int weight = edge.second; // The weight of the edge from u to v

                // Relaxation step: If a shorter path to v is found through u
                // Check if the new path time (dist[u] + weight) is less than the current
                // recorded distance to v AND if this new path time is less than the
                // disappear time of the neighbor node v.
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                     // Check if the new path time is within the disappear time of the neighbor
                    if (dist[u] + weight < disappear[v]) {
                        dist[v] = dist[u] + weight; // Update the distance to v
                        pq.push({dist[v], v}); // Push the updated vertex and distance into the priority queue
                    }
                }
            }
        }

        // Prepare the result vector.
        // If the shortest distance to a node is greater than or equal to its disappear time,
        // or if it's still INT_MAX (unreachable), set the result to -1.
        // Otherwise, set the result to the shortest distance.
        vector<int> result(n);
        for(int i = 0; i < n; ++i) {
            if (dist[i] == numeric_limits<int>::max() || dist[i] >= disappear[i]) {
                result[i] = -1;
            } else {
                result[i] = dist[i];
            }
        }

        return result;
    }
};
