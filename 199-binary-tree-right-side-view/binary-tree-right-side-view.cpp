class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};  // handle null root

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,int> mp;  // use map to keep levels sorted

        while(!q.empty()){
            auto [node, level] = q.front();
            q.pop();

            if(node){  // check null
                mp[level] = node->val;  // overwrite with rightmost node at this level
                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
            }
        }

        vector<int> answer;
        for(auto [level, val] : mp){  // correct naming
            answer.push_back(val);
        }
        return answer;
    }
};
