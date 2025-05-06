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
        TreeNode* node = findElement(root,val);
        return node;
    }
};