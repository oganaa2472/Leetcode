class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<int,int> dp;
        if(nums.size()<=2) return 0;
        int n = nums.size();
        int cur = 1;
        for(int i = 2;i<n;i++){
            int dif = nums[i]-nums[i-1];
            if(dif==nums[i-1]-nums[i-2]){
                dp[dif] += cur; 
                cur++;
            }
            else{
                cur = 1;
            }
        }
        int ans = 0;
        for(auto [x,y]:dp){
         
            ans+=y;
        }
        return ans;
    }
};