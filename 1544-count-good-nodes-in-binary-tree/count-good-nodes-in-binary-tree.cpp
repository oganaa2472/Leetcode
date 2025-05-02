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
    int ans = 1;
    void count(TreeNode* root,int mx){
        if(root==NULL) return;
        bool isAdd = root->val >= mx;
        ans=ans+isAdd;
        int mxVal = max(root->val,mx);
    
        count(root->left,mxVal);
        count(root->right,mxVal);        
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        count(root->left,root->val);
        count(root->right,root->val);
        return ans;
    }
};