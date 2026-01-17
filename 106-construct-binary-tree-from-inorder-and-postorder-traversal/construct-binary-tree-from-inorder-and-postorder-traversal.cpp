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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i = 0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder,int preStart,int preEnd, vector<int>& inorder,
    int inStart,int inEnd,map<int,int>& inMap
    ){
    if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[preEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot-inStart;
        root->left = buildTree(postorder,preStart,preStart+numsLeft-1,inorder,inStart,inRoot-1,inMap);
        root->right = buildTree(postorder,preStart+numsLeft,preEnd-1,inorder,inRoot+1,inEnd,inMap);
        return root;
    }
};