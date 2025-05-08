class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
         unordered_map<int, int> d;
            sort(nums.begin(),nums.end());

        int maxLength = 0;
        for (int num : nums) {
            d[num+1] = d[num]+1;
            d[num] = d[num - 1]+1;
            maxLength = max({maxLength, d[num],d[num+1]});
        }
        return maxLength;
    }
};