class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i =1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        long long totalSum = prefixSum[n-1];
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            if(prefixSum[i]>=totalSum-prefixSum[i]){
                cnt++;
            }
        }
        return cnt;
    }
};