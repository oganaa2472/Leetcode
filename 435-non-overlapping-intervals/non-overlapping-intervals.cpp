class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> merged;
        for(auto interval:intervals){
            if(!merged.empty()&&merged.back()[1]>interval[0]){
                
                merged[merged.size()-1][1] = min(merged.back()[1],interval[1]);
                
            }else{
                merged.push_back(interval);
            }
        }
        return n-merged.size();
    }
};