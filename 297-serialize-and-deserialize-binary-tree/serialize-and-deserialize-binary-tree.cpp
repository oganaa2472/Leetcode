class Codec {
public:

    // Serializes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "#,";
            }
        }
        return result;
    }

    // Deserializes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;
        stringstream ss(data);
        string value;
        getline(ss, value, ',');
        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (getline(ss, value, ',')) {
                if (value != "#") {
                    node->left = new TreeNode(stoi(value));
                    q.push(node->left);
                }
            }
            if (getline(ss, value, ',')) {
                if (value != "#") {
                    node->right = new TreeNode(stoi(value));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};