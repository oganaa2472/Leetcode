class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int i,vector<int>& nums,vector<int>& permute){
        if(i==n){
            result.push_back(permute);
            return;
        }
        for(int j = 0;j<nums.size();j++){
            
           auto it = find(permute.begin(),permute.end(), nums[j]);
           if(it!=permute.end()) continue;
           
            permute.push_back(nums[j]);
            solve(i+1,nums,permute);
            // remove 
            permute.pop_back();
        
            // remove 
           
            
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