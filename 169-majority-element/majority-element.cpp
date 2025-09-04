class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        int size = nums.size();
        int majorityElement = (size+1)/2;

        for(auto [key,value]:freq){
            if(value>=majorityElement){
                return key;
            }
        }
        return -1;
    }
};