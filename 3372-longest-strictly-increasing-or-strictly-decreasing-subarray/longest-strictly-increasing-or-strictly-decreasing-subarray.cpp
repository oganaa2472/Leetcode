class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int ans = 1;
        int c=1;
        int cur = -1;
        for(int i = 0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                c++;
                ans = max(c,ans);
            }else{
                c=1;
            }
        }
         ans = max(c,ans);
        c=1;
         for(int i = 0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                c++;
                ans = max(c,ans);
            }else{
                c=1;
            }
        }
        ans = max(c,ans);
        return ans;
        
    }
};