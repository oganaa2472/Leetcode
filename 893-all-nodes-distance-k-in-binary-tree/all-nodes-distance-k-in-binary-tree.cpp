// Definition for a binary tree node.


class Solution {
private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (node == nullptr) return;
        if (graph.find(node) == graph.end()) {
            graph[node] = vector<TreeNode*>();
        }
        if (parent != nullptr) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, nullptr, graph);
        
        // BFS initialization
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        
        // Starting BFS
        int distance = 0;
        while (!q.empty()) {
            if (distance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                for (TreeNode* neighbor : graph[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            distance++;
        }
        
        return vector<int>();
    }
};