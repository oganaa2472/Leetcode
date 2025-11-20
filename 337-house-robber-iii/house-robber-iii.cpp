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
    unordered_map<TreeNode*, int> memo;
    int robDFS(TreeNode* node){
        if(node==NULL) return 0;
        if(memo.find(node)!=memo.end()) return memo[node];

        int money = node->val;
        if (node->left != nullptr) {
            money += robDFS(node->left->left) + robDFS(node->left->right);
        }
        if (node->right != nullptr) {
            money += robDFS(node->right->left) + robDFS(node->right->right);
        }
        int notRobbing = robDFS(node->left) + robDFS(node->right);
        return memo[node] = max(money,notRobbing);
        
    }
    int rob(TreeNode* root) {
        return robDFS(root);
    }
};