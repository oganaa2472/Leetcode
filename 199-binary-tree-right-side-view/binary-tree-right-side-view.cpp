#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (!root) return rightView;  // Empty tree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* node = nullptr;
            // Traverse all nodes of the current level
            for (int i = 0; i < levelSize; ++i) {
                node = q.front();
                q.pop();
                
                // Push left and right children of current node if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // Add the last node seen on this level to the right view
            if (node) rightView.push_back(node->val);
        }

        return rightView;
    }
};