class Solution {
public:
    int n;
    unordered_map<string,int> dp;
    vector<int> arr;
    int solve(int i,int lastValue,int diff){
         if (i == n) return 0;
        
        string key = to_string(i)+"*"+to_string(lastValue);
        if (dp.count(key)) return dp[key];
        
        // Skip the current character
        int skip = solve(i + 1, lastValue, diff);
        int include = 0;
        if (lastValue == 10001 || (arr[i] - lastValue) == diff) {
            include = 1 + solve(i + 1, arr[i],diff);
        }
        return dp[key] = max(skip, include);

    }
    int longestSubsequence(vector<int>& arr, int dif) {
        n = arr.size();
        this->arr = arr;
        // dp.resize(n+1,vector<int>(20000+2,-1));
        // vector<int> dp(n,1);
        // vector<int> prev(n,1);
        // int ans = 1;
        // for(int i = 1;i<n;i++){
        //     for(int j = 0;j<i;j++){
        //         if(arr[i]-arr[j]==dif){
        //             dp[i] = max(dp[i],dp[j]+1);
        //             ans = max(dp[i],ans);
        //         }
        //     }
        // }
        // return ans;

        unordered_map<int, int> d;
        int maxLength = 0;
        for (int num : arr) {
            d[num] = d[num - dif] + 1;
            maxLength = max(maxLength, d[num]);
        }
        return maxLength;
    }
};