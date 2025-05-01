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
    vector<TreeNode*> result;
    vector<TreeNode*> generate(int left,int right){
        if(left==right) return {new TreeNode(left)};

        if(left>right){
            return {NULL};
        }
        vector<TreeNode*> res;
        for(int i = left;i<=right;i++){
            for(TreeNode* leftTree : generate(left,i-1))
                for(TreeNode* rightTree :generate(i+1,right)){
                    TreeNode* root = new TreeNode(i,leftTree,rightTree);
                    res.push_back(root);
                }
                
        }
        return res;

    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};