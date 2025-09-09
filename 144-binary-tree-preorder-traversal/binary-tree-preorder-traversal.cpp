#include <vector>

// Definition for a binary tree node.

class Solution {
public:
    // Helper function to perform preorder traversal recursively
    void preorderTraversalHelper(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr)
            return;

        // Step 1: Visit the root node
        result.push_back(node->val);
        // Step 2: Recursively traverse the left subtree
        preorderTraversalHelper(node->left, result);
        // Step 3: Recursively traverse the right subtree
        preorderTraversalHelper(node->right, result);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        preorderTraversalHelper(root, result);
        return result;
    }
};