class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        
        map<int,int> freeTime;
        freeTime[(startTime[0])]++;
        for (int i = 1; i < n; i++) {
            freeTime[(startTime[i] - endTime[i - 1])]++;
        }
        freeTime[(eventTime - endTime[n - 1])]++;

        
        int maxFree = 0;
        for (int i = 0; i < n; i++) {
            int width = endTime[i] - startTime[i];                       
            int prev = i>0?endTime[i-1]:0;
            int next = i < n-1 ? startTime[i+1] : eventTime;

            bool isExist = false;
            int gp1 = startTime[i] - prev;
            int gp2 = next - endTime[i];
            freeTime[gp1]--;
            freeTime[gp2]--;
            if (freeTime[gp1] <= 0 ) freeTime.erase(gp1);
            if (freeTime[gp2] <= 0 ) freeTime.erase(gp2);
            if ( (*freeTime.rbegin()).first >= width) isExist = true;
            freeTime[gp1]++;
            freeTime[gp2]++;
            if (isExist) maxFree = max(maxFree, next - prev);
            else maxFree = max(maxFree, next - prev - width);
        }
        return maxFree;
    }
};