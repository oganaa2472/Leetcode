class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int i,vector<int>& nums,vector<int>& chosen){
        if(i==n){
            result.push_back(chosen);
            return;
        }
        for(int j = 0;j<nums.size();j++){
            
            vector<int> t = nums;
            // remove 
            t.erase(t.begin()+j);
            chosen.push_back(nums[j]);
            solve(i+1,t,chosen);
            // remove 
            chosen.pop_back();
            // add
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> answer;
        n = nums.size();
        vector<int> t;
        solve(0,nums,t);
        return result;
    }
};