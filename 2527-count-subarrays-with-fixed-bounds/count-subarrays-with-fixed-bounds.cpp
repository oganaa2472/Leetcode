class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMin = -1;
        int lastMax = -1; 
        int lastInvalid = -1; 
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
             if(x < minK || x > maxK) {
                lastInvalid = i;
            }
            if(x == minK) lastMin = i;
            if(x == maxK) lastMax = i;
            count += max(0, min(lastMin, lastMax) - lastInvalid);
        }
        return count;
    }
    
};