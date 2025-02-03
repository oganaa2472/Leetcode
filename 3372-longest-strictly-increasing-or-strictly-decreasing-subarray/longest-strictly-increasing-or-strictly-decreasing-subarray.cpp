class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int c=1;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                c++;
                ans = max(ans,c);
            }else{
                c=1;
                  ans = max(ans,c);
            }            
        }
        c=1;
        for(int i = 0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                c++;
                  ans = max(ans,c);
            }else{
                c=1;
                  ans = max(ans,c);
            }            
        }
        return ans;
    }
};