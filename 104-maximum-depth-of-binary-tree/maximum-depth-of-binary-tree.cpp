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
    int res = 0;
    int dfs(TreeNode* root){
        if(root==NULL){return 1;}

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max({res,left,right});

        return 1+max(left,right);
    }
    int maxDepth(TreeNode* root) {
        dfs(root);
        return res;
    }
};