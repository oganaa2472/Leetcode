#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent; // parent[i] = parent of node i
    vector<int> rank;   // rank[i] = approx depth of tree rooted at i

public:
    // Constructor: initialize n nodes
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i; // initially, each node is its own parent
    }

    // Find with path compression
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return false; // already connected

        // Union by rank
        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    // Check if two nodes are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> merge;
        UnionFind dsu(n);
        for(int i = 0;i<n;i++){
            int accountSize = accounts[i].size();
            for(int j = 1;j<accountSize;j++){
                string email = accounts[i][j];
                string accName = accounts[i][0];

                if(merge.find(email)==merge.end()){
                    merge[email] = i;
                }else{
                    dsu.unite(i,merge[email]);
                }
            }
        }

        unordered_map<int,vector<string>> comp;

        for(auto [email,group]:merge){
             comp[dsu.find(group)].push_back(email);
        }

        vector<vector<string>> mergedAcc;
        for(auto com: comp){
            int group = com.first;
            vector<string> component={accounts[group][0]};
            component.insert(component.end(),com.second.begin(),com.second.end() );
            sort(component.begin()+1,component.end());
            mergedAcc.push_back(component);
        }
        return mergedAcc;
    }
};