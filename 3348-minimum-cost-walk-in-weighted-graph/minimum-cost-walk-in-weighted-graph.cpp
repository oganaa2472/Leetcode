#include <vector>
#include <numeric> // Required for std::iota
#include <algorithm> // Required for std::min and std::max
#include <limits> // Required for std::numeric_limits

// Represents the Union-Find data structure augmented to track the minimum bitwise AND of edge weights
class UnionFind {
private:
    std::vector<int> parent;    // Stores the parent of each element
    std::vector<int> size;      // Stores the size of the set for the root elements
    std::vector<int> min_bitwise_and; // Stores the minimum bitwise AND of edge weights in the set for root elements
    int num_sets;               // Stores the current number of disjoint sets

public:
    // Constructor: Initializes the Union-Find structure for 'n' elements.
    // Initially, each element is in its own set, and the min bitwise AND is INT_MAX.
    UnionFind(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i
        size.assign(n, 1); // Initially, each set has size 1

        // Initialize min_bitwise_and. For individual nodes (sets of size 1),
        // the concept of edge weight AND doesn't apply yet.
        // We initialize it to INT_MAX, which represents all bits set.
        // When merging, we'll AND this with edge weights.
        min_bitwise_and.assign(n, std::numeric_limits<int>::max());

        num_sets = n; // Initially, there are 'n' sets
    }

    // Find operation with Path Compression:
    // Returns the representative (root) of the set containing element 'i'.
    // During traversal, it makes all visited nodes point directly to the root.
    int find(int i) {
        // If i is the root of its set (parent[i] == i)
        if (parent[i] == i) {
            return i;
        }
        // Otherwise, recursively find the root and apply path compression
        // by setting parent[i] directly to the root.
        return parent[i] = find(parent[i]);
    }

    // Union operation with Union by Size and Min Bitwise AND Update:
    // Merges the sets containing elements 'i' and 'j' using an edge with 'weight'.
    // It attaches the root of the smaller tree to the root of the larger tree.
    // Updates the min_bitwise_and of the new root.
    // Returns true if the sets were successfully merged (i.e., they were different),
    // false otherwise (they were already in the same set).
    bool unite(int i, int j, int weight) {
        int root_i = find(i); // Find the root of i's set
        int root_j = find(j); // Find the root of j's set

        // If i and j are already in the same set, do nothing
        // If the problem requires updating the bitwise AND even if already connected
        // (e.g., considering alternative paths), you would update min_bitwise_and[root_i]
        // with min_bitwise_and[root_i] & weight here.
        if (root_i == root_j) {
            // If already connected, the bitwise AND of paths might be updated by this edge.
            // The problem statement implies we want the minimum AND over *any* path.
            // If they are already connected, adding this edge might create a new path.
            // The bitwise AND of weights on this new path would be
            // (min_bitwise_and of existing path) & weight.
            // The overall min bitwise AND for the component is the minimum over all paths.
            // For this specific problem type (minimum cost to connect, where cost is bitwise AND),
            // if they are already connected, adding this edge doesn't change the minimum bitwise AND
            // of paths *if* we process edges in some order (like decreasing weight for max AND,
            // or if any path is sufficient). The common interpretation for this type of problem
            // is that the bitwise AND of all edges in the component matters.
            // Let's update the bitwise AND even if connected, as the new edge adds to the set of edges in the component.
            min_bitwise_and[root_i] &= weight;
            return false; // Still return false as no new set was formed
        }

        // Calculate the new bitwise AND for the merged set *before* changing parent pointers
        int new_bitwise_and = min_bitwise_and[root_i] & min_bitwise_and[root_j] & weight;

        // Union by size: Attach the smaller tree to the larger tree's root
        if (size[root_i] < size[root_j]) {
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
            // Update min_bitwise_and for the new root (root_j)
            min_bitwise_and[root_j] = new_bitwise_and;
        } else {
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            // Update min_bitwise_and for the new root (root_i)
            min_bitwise_and[root_i] = new_bitwise_and;
        }

        // Since we successfully merged two different sets, the number of sets decreases by 1.
        num_sets--;

        return true; // Sets were successfully merged
    }

    // Get the size of the set containing element 'i'
    int getSize(int i) {
        return size[find(i)];
    }

    // Check if two elements are in the same set
    bool connected(int i, int j) {
        if (i < 0 || i >= parent.size() || j < 0 || j >= parent.size()) {
            // Handle out of bounds access if necessary, though problem constraints usually prevent this
            return false;
        }
        return find(i) == find(j);
    }

    // Get the number of disjoint sets
    int count() const {
        return num_sets;
    }

    // New method to get the minimum bitwise AND of edge weights
    // in the set containing element 'i'.
    int getMinBitwiseAND(int i) {
         if (i < 0 || i >= parent.size()) {
            // Handle out of bounds access
            return -1; // Or throw an exception
        }
        int root = find(i);
        // If the component has more than one node (i.e., edges have been added),
        // return the stored bitwise AND. If it's a single node component,
        // there are no edges, and the answer is typically -1 for queries
        // between two *different* nodes. For a query between a node and itself,
        // the answer might be 0 or INT_MAX depending on problem specifics,
        // but for connectivity problems, queries are usually between distinct nodes.
        // Based on the Solution class logic returning -1 if not connected,
        // and the nature of bitwise AND, INT_MAX implies no edges have contributed yet.
        // If the component size > 1, we have edges and a meaningful bitwise AND.
        // If size is 1, it's an isolated node, no paths to other nodes in the component.
        if (size[root] > 1) {
             return min_bitwise_and[root];
        } else {
             // If the component only has one node, there are no paths *between different nodes*
             // within this component. The query is likely between two different nodes.
             // If the query is between the same node (u==v), the answer depends on problem spec.
             // Assuming queries are between distinct nodes, an isolated node cannot be connected
             // to another distinct node within its component.
             return -1; // Or handle based on problem constraints for u==v query
        }
    }
};

class Solution {
public:
    std::vector<int> minimumCost(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& query) {
        // Sort edges by weight in ascending order if the problem required minimum total weight (like MST).
        // For minimum bitwise AND over *any* path, the order of adding edges doesn't matter
        // for the final connected components and their bitwise AND property, as bitwise AND is associative.
        // However, if the problem implies processing edges in a specific order (e.g., given order),
        // we use the given order. Let's assume the given order is the order to process.

        UnionFind uf(n);

        // Correct loop condition: iterate through the number of edges
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            uf.unite(u, v, w); // Use u, v, w as per edge format
        }

        int m = query.size();
        std::vector<int> result(m,-1);

        for(int i = 0; i < m; ++i){
            int u = query[i][0];
            int v = query[i][1];

            // If the query is for the same node, the path has 0 edges.
            // The bitwise AND of an empty set of weights is typically considered INT_MAX or 0
            // depending on context. For connectivity problems, u==v might have a special answer.
            // Let's assume for u==v, the answer is the bitwise AND of the component if size > 1
            // or -1 if size == 1 (no path to another node). Or maybe 0 if u==v is always connected to itself.
            // Based on typical LeetCode problems, if u==v, the answer is often 0 or the value itself,
            // but the problem constraints usually clarify. If they must be different nodes,
            // the connected check is sufficient.
            if (u == v) {
                 // If u and v are the same, they are trivially connected.
                 // The bitwise AND of weights on a path from u to u is usually considered 0.
                 // Let's return 0 for u == v queries.
                 result[i] = 0;
            } else if(uf.connected(u, v)){
                // If u and v are connected and different nodes, get the min bitwise AND of their component.
                // The getMinBitwiseAND method already handles the case where the component size is 1.
                result[i] = uf.getMinBitwiseAND(u);
            } else {
                // If u and v are not connected, the result is -1.
                result[i] = -1;
            }
        }
        return result;
    }
};
