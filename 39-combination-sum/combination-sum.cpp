class Solution {
public:
    vector<vector<int>> answer;
    int size ;
    vector<int> can;
    void solve(
        int i,int target,vector<int>& ans
    ){
        if(target<0||i>=size) return ;
        if(target==0){
            answer.push_back(ans);
            return;
        }
        solve(i+1,target,ans);
        if(target-can[i]>=0){
            ans.push_back(can[i]);
            solve(i,target-can[i],ans);
            ans.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;

        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        int prev = -1;
        for(int i = 0;i<n;i++){
            if(prev==-1) can.push_back(candidates[i]);
            
            else if(prev==candidates[i]) continue;
            else can.push_back(candidates[i]);
            prev=candidates[i];
        }
        size = can.size();
        vector<int> ans;
        solve(0,target,ans);
        return answer;
    }
};