/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        map<int,vector<int>> answer;
        q.push({0,root});
        while(!q.empty()){
            auto [level,next] = q.front();
            if(next!=NULL) answer[level].push_back(next->val); 
            q.pop();
            if(next!=NULL&&next->left!=NULL) q.push({level+1,next->left});
            if(next!=NULL&&next->right!=NULL) q.push({level+1,next->right});
            
        }
        vector<vector<int>> result;
        for(auto [level,values]:answer){
            if(level%2==1) reverse(values.begin(),values.end());
            
            result.push_back(values);
        }
        return result;

    }
};