class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(*nums.begin()<k) return -1;
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int count = 0;
       
        for(auto& [x,y]:m){
            if(x>k) count++;
        }
        return count;
    }
};