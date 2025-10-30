class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }   
        for(auto [x,values]:mp){
            for(int i = 0;i<values.size()-1;i++){
                if(values[i+1]-values[i]<=k) return true;
            }
       
        }
        return false;
    }
};