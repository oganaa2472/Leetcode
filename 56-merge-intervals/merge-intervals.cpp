class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> answer;
        
        for(int i = 0;i<intervals.size();i++){
            if(!answer.empty()&&answer.back()[1]>=intervals[i][0]){
               answer[answer.size()-1][1] = max(intervals[i][1],answer[answer.size()-1][1]);
            }else{
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};