class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxSum = 0,m = 0;
        vector<pair<int,pair<bool,int>>> timeline;
        for(auto &e:events){
            int start = e[0];
            int end = e[1];
            int val = e[2];
            timeline.push_back({start,{true,val}});
            timeline.push_back({end+1,{false,val}});
        }

        sort(timeline.begin(),timeline.end());

        for(auto t:timeline){
            bool isStart = t.second.first;
            int value = t.second.second;

            if(isStart){
                maxSum = max(maxSum,m+value);
            }else{
                m = max(m,value);
            }
        }
        return maxSum;
    }
};