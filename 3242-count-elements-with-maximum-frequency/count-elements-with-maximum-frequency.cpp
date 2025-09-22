class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx = 0;
        int count = 0;
        // You are given nums consisting of positive integers
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
            mx = max(mx,mp[nums[i]]);
        }
        for(auto [x,y]:mp){
            if(mx==y){
                count++;
            }
        }
        
        return mx*count;
    }
};