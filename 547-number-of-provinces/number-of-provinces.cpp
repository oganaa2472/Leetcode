class UnionFind {
private:
    vector<int> parent; // Stores the parent of each element
    vector<int> size;   // Stores the size of the set for the root elements
    int num_sets;            // Stores the current number of disjoint sets

public:
    // Constructor: Initializes the Union-Find structure for 'n' elements.
    // Initially, each element is in its own set, and the number of sets is 'n'.
    UnionFind(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i
        size.assign(n, 1); // Initially, each set has size 1
        num_sets = n;      // Initially, there are 'n' sets
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

    // Union operation with Union by Size:
    // Merges the sets containing elements 'i' and 'j'.
    // It attaches the root of the smaller tree to the root of the larger tree.
    // Returns true if the sets were successfully merged (i.e., they were different),
    // false otherwise (they were already in the same set).
    bool unite(int i, int j) {
        int root_i = find(i); // Find the root of i's set
        int root_j = find(j); // Find the root of j's set

        // If i and j are already in the same set, do nothing
        if (root_i == root_j) {
            return false;
        }

        // Union by size: Attach the smaller tree to the larger tree's root
        if (size[root_i] < size[root_j]) {
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
        } else {
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }

        // Since we successfully merged two different sets, the number of sets decreases by 1.
        num_sets--;

        return true; // Sets were successfully merged
    }

    // Optional: Get the size of the set containing element 'i'
    int getSize(int i) {
        return size[find(i)];
    }

    // Optional: Check if two elements are in the same set
    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    // New method to get the number of disjoint sets
    int count() const {
        return num_sets;
    }
};
class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    uf.unite(i,j);
                }
            }
        }
        return uf.count();
        
    }
};