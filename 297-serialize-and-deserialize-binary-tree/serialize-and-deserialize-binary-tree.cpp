class Codec {
public:

    // Serializes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Deserializes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            nodes.push(node);
        }
        return deserializeHelper(nodes);
    }

private:

    TreeNode* deserializeHelper(queue<string>& nodes) {
        string value = nodes.front();
        nodes.pop();
        if (value == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(value));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }
};