class Solution {
public:
    // Helper function for inorder traversal and tracking the k-th element
    int inorderTraversal(TreeNode* root, int& k) {
        if (root == nullptr) return -1;
        
        // LEFT: Dive into the left subtree
        int left = inorderTraversal(root->left, k);
        if (k == 0) return left;  // If we've found the k-th element in the left subtree, return it
        
        // NODE: Process the current node
        k--;  // Visiting the current node, decrement k
        if (k == 0) return root->val;  // If after decrementing, k is zero, this is the k-th element
        
        // RIGHT: Dive into the right subtree
        return inorderTraversal(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
    }
};