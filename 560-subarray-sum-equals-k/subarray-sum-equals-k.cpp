class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefix = 0;
        int res = 0;
        for(int num:nums){
            prefix+=num;
            res=res+mp[prefix-k];
            mp[prefix]++;
        }
        return res;
    }
};