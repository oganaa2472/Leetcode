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
    int isBal(TreeNode* root){
        if(root==NULL) return 0;
        int left =isBal(root->left);
        int right =isBal(root->right);

        if(left==-1) return -1;
        if(right==-1) return -1;
        if(abs(left-right)>1) return -1;
       
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return isBal(root)==-1?false:true;
    }
};