class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            int j = i;
            int sum = nums[j];
            while(j+1<n&&nums[j]<nums[j+1]){
                sum = sum+nums[j+1];
                j++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};