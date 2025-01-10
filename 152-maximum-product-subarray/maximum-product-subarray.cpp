class Solution {
public:
  
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    
        
        int mx = nums[0];
        int ans = mx;
        ans = max(ans,nums[n-1]);
        for(int i = 1 ;i<n;i++){
            mx = nums[i-1];
            ans = max(nums[i-1],ans);
            for(int j = i;j<n;j++){
                mx = mx * nums[j];
                ans = max(ans,mx);
            }
        }
        
        
        return ans;

    }
};