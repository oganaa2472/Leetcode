class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int totalMask = nums.size();
        set<vector<int>> uniqueSubsets;
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        for(int mask=0;mask<(1<<totalMask);mask++){
            vector<int> subs;
            for(int j = 0;j<totalMask;j++){
                if(mask&(1<<j)){
                     subs.push_back(nums[j]);
                }
            }
            uniqueSubsets.insert(subs);
        }
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());

    }
};