class Solution {
public:
    vector<vector<int>> result;
    void solve(int i,vector<int>& ans,int sum,int target,vector<int> &can){
        int n = can.size();
        if(i>=n||target<sum) return;
        if(sum==target){
            result.push_back(ans);
            return;
        } 
        for(int j = i;j<n;j++){
            ans.push_back(can[j]);
            solve(j,ans,sum+can[j],target,can);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> answer;
        solve(0,answer,0,target,candidates);
        return result;
    }
};