class Solution {
public:
    vector<vector<int>> answer;
    int size ;
    vector<int> can;
    void solve(
        int i,int target,vector<int>& ans
    ){
        if(target<0) return ;
        if(target==0){
            answer.push_back(ans);
        }else{
            for(int j = i;j<can.size();j++){
                if(j>i&&can[j]==can[j-1]) continue;
                ans.push_back(can[j]);
                solve(j+1,target-can[j],ans);
                ans.pop_back();
            }
        }
        


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;

        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        can = candidates;
        // int prev = -1;
        // for(int i = 0;i<n;i++){
        //     if(prev==-1) can.push_back(candidates[i]);
            
        //     else if(prev==candidates[i]) continue;
        //     else can.push_back(candidates[i]);
        //     prev=candidates[i];
        // }
        size = n;
        vector<int> ans;
        solve(0,target,ans);
        return answer;
    }
};