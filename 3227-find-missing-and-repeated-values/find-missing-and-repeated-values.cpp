class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int,int> mp ;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                mp[grid[i][j]]++;
            }
        }
        vector<int> ans;
        int a1;
        int a2;
        for(int i = 1;i<=n*n;i++){
            if(mp[i]==0){
                a1 = i;
            }if(mp[i]>1){
                a2 = i;
            }
        }
        ans.push_back(a2);
        ans.push_back(a1);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};