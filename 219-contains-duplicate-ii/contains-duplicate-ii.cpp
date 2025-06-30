class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int r = 0;
        int l = 0;
        unordered_set<int> window;
        while(r<nums.size()){
            
            if(r-l>k){
                window.erase(nums[l]);
                l++;
            }
            if(window.find(nums[r])!=window.end()){
                return true;
            }
            window.insert(nums[r]);
            r++;
        }
        return false;
    }
};