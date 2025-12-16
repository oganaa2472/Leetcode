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
    int cameras = 0;

    // State: 0 = Not covered, 1 = Covered, 2 = Has camera
    int dfs(TreeNode* node) {
        if (!node) return 1; // Null node-уудыг хянагдсан гэж үзнэ

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 0 || right == 0) {
            // Хэрвээ ямар нэг child хянагдаагүй бол энэ node дээр кэмер тавина
            cameras++;
            return 2; // Энэ node дээр кэмер тавигдсан
        } else if (left == 2 || right == 2) {
            // Хэрвээ ямар нэг child дээр кэмер байгаа бол энэ node хянагдсан
            return 1;
        } else {
            // Энэ node хянагдаагүй
            return 0;
        }
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            // Root өөрөө хянагдаагүй бол кэмер нэмнэ
            cameras++;
        }
        return cameras;
    }
};
