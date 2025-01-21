class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n==1) return 0;
        vector<long long> prefixSum(n,0),suffix(n,0);
        prefixSum[0] = grid[0][0];
        suffix[0] = grid[1][0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1]+grid[0][i];
            // cout<<prefixSum[i]<<" ";
            suffix[i] = suffix[i-1]+grid[1][i];
            // cout<<suffix[i] <<" ";
        }
    
        // int index = -1;
        int index = -1;
        long long ans = prefixSum[n-1]-prefixSum[0];
        ans = min(ans,suffix[n-2]);
        for(int i = 1;i<n-1;i++){
            long long pref = prefixSum[n-1]-prefixSum[i];
            long long suf = suffix[i-1];
               ans =
                min({ans,max(pref,suf)});
            
        }
        return ans;
    }
};