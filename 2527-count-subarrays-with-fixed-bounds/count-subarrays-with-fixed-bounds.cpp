class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMin = -1;       // minK-г сүүлийн удаа үзсэн индекс
        int lastMax = -1;       // maxK-г сүүлийн удаа үзсэн индекс
        int lastInvalid = -1; 
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            // Хэрвээ элемент minK..maxK-ийн хязгаараас гадуур бол invalid
            
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