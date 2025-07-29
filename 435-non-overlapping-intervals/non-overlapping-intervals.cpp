class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });

        int n = intervals.size();
        vector<vector<int>> merged;
        for(int i = 0;i<n;i++){
            if(!merged.empty()&&merged.back()[1]>intervals[i][0]){
                int sz = merged.size();
                merged[sz-1][1] = min(merged.back()[1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return n-merged.size();
    }
};