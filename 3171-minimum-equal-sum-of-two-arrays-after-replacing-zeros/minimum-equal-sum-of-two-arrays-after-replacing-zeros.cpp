class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long S1 = accumulate(nums1.begin(),nums1.end(),0LL);
        long long S2 = accumulate(nums2.begin(),nums2.end(),0LL);
        unordered_map<long long,long long> z1,z2;
        for(auto num:nums1) z1[num]++;
        for(auto num:nums2) z2[num]++;
        
        S1+=(long long)z1[0];
        S2+=(long long)z2[0];
         if (!z1[0] && S2 > S1 || !z2[0] && S1 > S2) {
            return -1;
        }
        return max(S1, S2);

    }
};