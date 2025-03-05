class Solution {
public: 
    int n;
    bool checkMyArray(vector<int> dp,int k,int n){
        for(int i =0;i<n-k;i++){
            if(dp[i]>=k&&dp[i+k]>=k) return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {

        /*
        Given an array nums of n integers, your task is to find the maximum value of k for which there exixt
        2 adjacent subbarrays of length k each, such that both subarrays strictly increasing
        Specially, check if there are 2 subarrays of length k starting at indices a and b a<b 
        */

        // n = nums.size();
        // vector<int> dp(n+1,1);
        // int mx_val = 0;
        // for(int i = n-2;i>=0;i++){
        //     if(nums[i+1]>nums[i]){
        //         dp[i] = dp[i+1] + 1;
        //         mx_val = max(dp[i],mx_val);
        //     }
        // }

        // int left = 0,right = mx_val;
        // while(left<right){
        //     int mid = left+(right-left)/2;
        //     if(checkArray(dp,mid)){

        //     }
        // }
        int n = nums.size();
        vector<int> dp(n+1,1);
        unordered_map<int,int> mp ;
        int answer = -1;
        int mx = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {
                dp[i] = dp[i+1]+1;
                mx = max(mx,dp[i]);
            }
        }
        int left = 0,right = mx;
        while(left<=right){
            int mid = (left) + (right-left)/2;
            if(checkMyArray(dp,mid,n)){
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        return max(left-1,max(mx/2,1));


    }
};