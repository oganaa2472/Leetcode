class Solution {
public:
     
    int lenLongestFibSubseq(vector<int>& arr) {
        int answer = 0;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
       
        for(int i = 2;i<n;i++){
            
            int start = 0;
            int end = i-1;
            while(start<end){
                if(arr[start]+arr[end]>arr[i]){
                    end--;
                }else if(arr[start]+arr[end]<arr[i]){
                    start++;
                }else{
                    dp[end][i] = dp[start][end]+1;
                    answer=max(dp[end][i],answer);
                    end--;
                    start++;
                   
                }
            }
        }
        return answer==0?0:answer+2;
    }
};