class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto num:nums){
            freq[num]++;
        }
        int majElement = (nums.size()+1)/2;
        for(auto [num,fre]:freq){
            if(fre>=majElement){
                return num;
            }
        }
        return -1;
    }
};