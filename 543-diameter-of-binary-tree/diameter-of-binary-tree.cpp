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
    int height(int& d,TreeNode* node){
        if(node==NULL) return 0;
        int left = height(d,node->left);
        int right = height(d,node->right);
        d = max(d,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(d,root);
        return d;
    }

};