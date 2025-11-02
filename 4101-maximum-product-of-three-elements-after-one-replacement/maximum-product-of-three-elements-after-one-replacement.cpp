typedef long long ll;
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ll mx1 = nums[n-1];
        ll mx2 = nums[n-2];
        ll mn1 = nums[0];
        ll mn2 = nums[1];
        ll rep1 = 1e5;
        ll rep2 = -1e5;
        ll possible1 = max(mx1*mx2*rep1,mn1*mn2*rep1);
        ll possible2 = mx1*mn1*rep2;
        return max(possible1,possible2);
    }
};