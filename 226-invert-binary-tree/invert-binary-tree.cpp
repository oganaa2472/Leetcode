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
    void dfs(TreeNode* root){
        if(root==NULL) return;
        // if(root->left!=NULL&&root->right!=NULL){
            
            swap(root->left,root->right);
            // root->left->val = right;
            // root->right->val = left;
            
        // }   
        dfs(root->right);
        dfs(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};