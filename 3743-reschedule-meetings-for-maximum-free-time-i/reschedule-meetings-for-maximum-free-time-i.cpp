
class Solution {
public:
    int maxFreeTime(int eventTime,int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime[n - 1]);

        
        int maxFree = 0;
        int j = 0;
        int sum = 0;
        k++;
        for (int i = 0; i < freeTime.size(); i++) {
                                   
            while (j<k+i&&j<freeTime.size()) {
                sum = sum + freeTime[j];
                // cout<<sum;
                j++;
            }
            maxFree = max(maxFree, sum);
            sum = sum - freeTime[i];
            
        }

        return maxFree;
    }
};