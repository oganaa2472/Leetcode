class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTreesHelper(1, n);
    }
    
private:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> allTrees;
        // If there is no number to form a tree
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }
        
        // Pick a root
        for (int i = start; i <= end; i++) {
            // Recursively find all left subtrees with nodes less than i
            vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
            // Recursively find all right subtrees with nodes greater than i
            vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);
            
            // Connect each left and right subtree to the current root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.push_back(currentTree);
                }
            }
        }
        return allTrees;
    }
};