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
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int> leftPair = dfs(root->left);
        pair<int,int> rightPair = dfs(root->right);
        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first,leftPair.second) +max(rightPair.first,rightPair.second);
        return {withRoot,withoutRoot};
    }
    int rob(TreeNode* root) {
        pair<int,int> f= dfs(root);
        return max(f.first,f.second);
    }
};