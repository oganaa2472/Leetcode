class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long,int> seen;
        seen[0] = 1;
        int sum = 0;
        int c = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
            c += seen[sum-k];
            seen[sum]++;
        }return c;
    }
};