class Solution {
public:
   
    // Helper function to count paths starting with specific node
    long long  solve(TreeNode* node, long long targetSum) {
        if (node == nullptr) return 0;
        long long paths = 0;
        if (node->val == targetSum) // Check if the node itself is a valid path
            paths++;
        // Explore the left and right subtree
        paths+= solve(node->left, targetSum - node->val);
        paths+= solve(node->right, targetSum - node->val);
        return paths;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        long long path = solve(root,targetSum);
        // Calculate the paths from the root node
        path+=pathSum(root->left,targetSum);
        path+=pathSum(root->right,targetSum);
        return path;
    }
};