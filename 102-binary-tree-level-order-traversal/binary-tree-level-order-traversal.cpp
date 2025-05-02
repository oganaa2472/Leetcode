class Solution {
public:
    vector<vector<int>> levelOrderRec(TreeNode* root,vector<vector<int>>&list,int level){
        if(root==NULL){
            return list;
        }
        if(level==list.size()){
            list.push_back({});
        }
        list[level].push_back(root->val);
        levelOrderRec(root->left,list,level+1);
        levelOrderRec(root->right,list,level+1);
        return list;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
    //     if (!root) return {}; // Handle empty tree
        
    //     vector<vector<int>> answer;
    //     queue<pair<TreeNode*, int>> pq;  // Store (node, level)
    //     pq.push({root, 0});
        
    //     vector<int> ans;
    //     int prev_level = -1;
    //    // bfs 
    //     while (!pq.empty()) {
    //         auto [node, level] = pq.front();
    //         pq.pop();
            
    //         if (level != prev_level) { // New level
    //             if (!ans.empty()) answer.push_back(ans);
    //             ans.clear();
    //             prev_level = level;
    //         }
            
    //         ans.push_back(node->val);
            
    //         if (node->left) pq.push({node->left, level + 1});
    //         if (node->right) pq.push({node->right, level + 1});
    //     }
        
    //     if (!ans.empty()) answer.push_back(ans); // Push last level
        
    //     return answer;
            vector<vector<int>> list;
            return levelOrderRec(root,list,0);
    }
};
