class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        if(nums.size()==freq.size()) return 0;
        int n = nums.size();
        freq.clear();
        int cur = 0;
       
        for(int i = n-1;i>=0;i--){
            if(freq.count(nums[i])){
                return i/3+1;
            }else{
                freq[nums[i]]++;
            }
        }
        return 0;
    }
};