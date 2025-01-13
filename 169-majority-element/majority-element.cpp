class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> maj;
        int n = (nums.size()+1)/2;

        for(int i = 0;i<nums.size();i++){
            maj[nums[i]]++;
        }
        for(auto [x,y]:maj){
            if(y>=n) return x;
        }return -1;
    }
};