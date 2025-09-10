class Solution {
public:
    void inorderTraversalHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;  // Base case: if the node is empty
        inorderTraversalHelper(root->left, result);  // Traverse left subtree
        result.push_back(root->val);  // Visit the root
        inorderTraversalHelper(root->right, result);  // Traverse right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(root, result);  // Start the recursive function
        return result;
    }
};