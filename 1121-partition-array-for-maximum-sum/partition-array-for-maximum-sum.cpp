class Solution {
public:
    int n,k;
    vector<int> dp,arr;
    int solve(int i){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans = INT_MIN;
        int len=0;
        int m=INT_MIN;

        for(int j = i;j<min(i+k,n);j++ ){
            len++;
            m = max(m,arr[j]);
            ans = max(ans,m*len + solve(j+1));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr = arr;
        n = arr.size();
        this->k=k;
        dp.resize(n+1,-1);
        return solve(0);
    }
};