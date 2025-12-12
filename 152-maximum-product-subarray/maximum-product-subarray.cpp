class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();
    int curMax = nums[0] ;
    int curMin = nums[0];
    int ans = nums[0];
    for(int i = 1;i<n;i++){
        int x = nums[i];

        // түр хадгална, учир нь curMax өөрчлөгдөнө
        int tempMax = max({x, curMax * x, curMin * x});
        int tempMin = min({x, curMax * x, curMin * x});
        curMax = tempMax;
        curMin = tempMin;

        ans = max(ans, curMax);
    }
    return ans;
    }
};