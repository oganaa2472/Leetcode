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
    TreeNode* dfs(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* temp = root;
        TreeNode* left = dfs(root->left);        
        TreeNode* right = dfs(root->right);
        temp->right = left;
        temp->left = right;
        return temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        root = dfs(root);
        return root;
    }
};