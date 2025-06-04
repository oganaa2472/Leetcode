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
    int pathLength = 0;
    void dfs(TreeNode* node,bool left,int step){
        if(node==NULL) return;
        pathLength = max(pathLength,step);
        if(left){
           dfs(node->left, false, step + 1); 
           dfs(node->right, true, 1); 
        }else{
            dfs(node->left, false, 1); 
            dfs(node->right, true, step+1); 
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        return pathLength;
    }
};