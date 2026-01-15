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
    int maxSum(int& answer,TreeNode* node){
        if(node==NULL){
            return INT_MIN;
        }
        int left = maxSum(answer,node->left);
        int right = maxSum(answer,node->right);
        if(right < 0) right = 0;
        if(left < 0) left = 0;
        int sum = node->val+right+left;
        answer = max({answer,sum});
        return max(left,right)+node->val;;

    }
    int maxPathSum(TreeNode* root) {
        int answer = INT_MIN;
        maxSum(answer,root);
        return answer;
    }
};