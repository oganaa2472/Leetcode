class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ops = 0;

        int appendCost = INT_MAX;
        int n = nums1.size();
        int lastVal = nums2.back();

        for(int i = 0;i<n;i++){
           int high = max(nums1[i], nums2[i]);
            int low = min(nums1[i], nums2[i]);
            if (low <= lastVal && lastVal <= high) {
                appendCost = 0;
            }else{
                appendCost = min(appendCost, min(abs(high - lastVal), abs(low - lastVal)));
            }

             ops += abs(nums1[i] - nums2[i]);
        }
        return ops + appendCost+1;

    }
};