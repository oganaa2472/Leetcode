class Solution {
public:
    TreeNode* helper(vector<int>&nums, int start, int end){
        int mid = start+(end-start)/2;
        if(start>end) return nullptr;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=helper(nums, start, mid-1);
        root->right=helper(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return helper(nums, 0, nums.size()-1);
    }
};