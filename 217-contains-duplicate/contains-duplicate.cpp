class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set st(nums.begin(),nums.end());

        if(nums.size()==st.size()) return false;
        return true;
    }
};