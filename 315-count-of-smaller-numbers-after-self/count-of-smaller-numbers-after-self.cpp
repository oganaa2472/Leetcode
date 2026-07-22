class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        vector<int> sorted;
        for (int i = nums.size() - 1; i >= 0; --i) {
           
            auto insert_pos = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            int count = insert_pos - sorted.begin();
            result.push_back(count);
        
            sorted.insert(insert_pos, nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};