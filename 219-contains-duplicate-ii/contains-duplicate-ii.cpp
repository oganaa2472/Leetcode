class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

    
        int n = nums.size();
    

        unordered_set<int> window; 

        for (int i = 0; i < n; i++) {
            if (window.find(nums[i]) != window.end()) {
                return true;
            }

       
            window.insert(nums[i]);

           
            if (i >= k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }

};