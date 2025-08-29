class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // merge them 

        vector<vector<int>> result;
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        for(int i = 0;i<n;i++){
            if(!merged.empty()&&merged.back()[1]>=intervals[i][0]){
                merged[merged.size()-1][1] = max(intervals[i][1],merged.back()[1]);
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};