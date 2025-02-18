class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  
        vector<vector<int>> merged;
        int n = intervals.size();

        for(int i = 0;i<n;i++){
            
           if (!merged.empty() && merged.back()[1] >= intervals[i][0]) {
                // int lastElement = 
               merged[merged.size()-1][1] = max(intervals[i][1],merged.back()[1]);
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;

    }
};