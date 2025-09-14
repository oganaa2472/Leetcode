class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        unordered_map<int,int> mp;
        vector<int> res;
        for(int i = nums.size() - 1; i >=0 ; i--) {

            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]]++;
                res.push_back(nums[i]);
                k--;

                if(k == 0) break;
            }
        }

        return res;
    }
};