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
    bool dfs(TreeNode* tree,long long min_val,long long max_val){

        if(tree==NULL) return true;
        if(tree->val<=min_val||tree->val>=max_val){
            return false;
        }
        return dfs(tree->left,min_val, tree->val)&&dfs(tree->right,tree->val,max_val);
    }
    bool isValidBST(TreeNode* root) {
       
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
};