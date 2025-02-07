class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        int a = 0;
        for(int i=0;i<nums.size();i++){
            a ^= nums[i];
        }
        return a;
    }
};