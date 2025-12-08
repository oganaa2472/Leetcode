class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
       const int MOD = 1e9 + 7;
    long long sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    while(i < n1 || j < n2) {
        if(i < n1 && (j == n2 || nums1[i] < nums2[j])) {
            sum1 += nums1[i++];
        } else if(j < n2 && (i == n1 || nums1[i] > nums2[j])) {
            sum2 += nums2[j++];
        } else { // nums1[i] == nums2[j]
            long long maxSum = max(sum1, sum2) + nums1[i];
            sum1 = maxSum;
            sum2 = maxSum;
            i++;
            j++;
        }
    }

    return max(sum1, sum2) % MOD;

    }
};