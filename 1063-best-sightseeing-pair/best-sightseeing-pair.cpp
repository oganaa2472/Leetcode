class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int curMax = values[0]-1;

        for(int i = 1;i<n;i++){
            ans = max(ans,curMax+values[i]);
            curMax = max(curMax-1,values[i]-1);
        }
        return ans;
    }
};