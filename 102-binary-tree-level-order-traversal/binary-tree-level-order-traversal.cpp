class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; // Handle empty tree
        
        vector<vector<int>> answer;
        queue<pair<TreeNode*, int>> pq;  // Store (node, level)
        pq.push({root, 0});
        
        vector<int> ans;
        int prev_level = -1;
        
        while (!pq.empty()) {
            auto [node, level] = pq.front();
            pq.pop();
            
            if (level != prev_level) { // New level
                if (!ans.empty()) answer.push_back(ans);
                ans.clear();
                prev_level = level;
            }
            
            ans.push_back(node->val);
            
            if (node->left) pq.push({node->left, level + 1});
            if (node->right) pq.push({node->right, level + 1});
        }
        
        if (!ans.empty()) answer.push_back(ans); // Push last level
        
        return answer;
    }
};
