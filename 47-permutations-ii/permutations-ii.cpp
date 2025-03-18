class Solution {
public:
 vector<vector<int>> ans;
 set<vector<int>> answer;
    void recursion(int n,vector<int>& nums){
        if(n == nums.size()){
            answer.insert(nums);
            return;
        }
        for(int i = n; i < nums.size(); i++){
            swap(nums[i],nums[n]);
            recursion(n+1,nums);
            swap(nums[i],nums[n]);
        }
        return;
    }
 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         recursion(0, nums);

         for(auto it:answer){
             ans.push_back(it);
         }
         return ans;
    }
};