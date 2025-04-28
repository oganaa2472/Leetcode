class Solution {
public:
    int n;
    vector<vector<int>> answer;
    vector<int> arr;
    void solve(int i,int target,vector<int> ans){
        if(target<0) return;
        if(target==0){
            answer.push_back(ans);
            return;
        }
        for(int j = i;j<n;j++){
            if(j>i&&arr[j]==arr[j-1]){
                continue;   
            }
            ans.push_back(arr[j]);
            solve(j+1,target-arr[j],ans);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        n = candidates.size();  
        this->arr = candidates;
        vector<int> ans;
        solve(0,target,ans);
        return answer;
    }
};