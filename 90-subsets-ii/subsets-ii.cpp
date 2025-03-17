class Solution {
public:
    vector<vector<int>> answer;
    int size ;
    vector<int> can;
    void solve(
        int i,vector<int>& ans
    ){
        
        
        answer.push_back(ans);
        
        for(int j = i;j<can.size();j++){
            if(j>i&&can[j]==can[j-1]) continue;
            ans.push_back(can[j]);
            solve(j+1,ans);
            ans.pop_back();
        }
        
        


    }
    vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
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
        solve(0,ans);
        return answer;
    }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     int totalMask = nums.size();
    //     set<vector<int>> uniqueSubsets;
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> answer;
    //     for(int mask=0;mask<(1<<totalMask);mask++){
    //         vector<int> subs;
    //         for(int j = 0;j<totalMask;j++){
    //             if(mask&(1<<j)){
    //                  subs.push_back(nums[j]);
    //             }
    //         }
    //         uniqueSubsets.insert(subs);
    //     }
    //     return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());

    // }
};