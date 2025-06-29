class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mod = 1e9+7;
        int ans = 0;
        vector<int> exp(n,1);
        for(int i = 1;i<n;i++){
            exp[i] = (exp[i-1]*2)%mod;
        }
        int right = n - 1;
        int left = 0;
            while(left<=right)
            if(nums[left]+nums[right]>target){
                right--;
            }else{
                ans+=exp[right-left];
                ans=ans%mod;
                left++;
            }
            
        
        return ans;
    }
};