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
    TreeNode* findElement(TreeNode* node, int val){
        if(node == NULL) return NULL;
        if(node->val == val){
            return node;
        }
        else if(node->val < val){
            return findElement(node->right,val);
        }
        else if(node->val > val){
            return findElement(node->left,val);
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val==val) return root;
        else if(root->val>val) return searchBST(root->left,val);
        else {
            return searchBST(root->right,val);
        }
        return root;
    }
};