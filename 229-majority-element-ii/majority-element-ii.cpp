class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<int> res;
        for (auto& pair : count) {
            if (pair.second > nums.size() / 3) {
                res.push_back(pair.first);
            }
        }
        
        return res;
    }
};