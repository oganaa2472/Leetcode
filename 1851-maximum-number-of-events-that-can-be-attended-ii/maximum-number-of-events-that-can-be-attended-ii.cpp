class Solution {
public:
    vector<vector<int>> dp;
    int n ;
    
    vector<vector<int>> events;
    int upperBound(int i){
        int left = i+1;
        int right = n-1;
        int nextIndex = n;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(events[i][1]<events[mid][0]){
                nextIndex = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return nextIndex;
    }
    int solve(int i,int k){
     
        if(i==n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int notPick = solve(i+1,k);
        int pick = 0;
        if(k>0){
            int nextIndex = upperBound(i);
            pick =events[i][2] + solve(nextIndex,k-1);
        }
        return dp[i][k] = max(pick,notPick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        this->events = events;
        n = events.size();
        dp.resize(n,vector<int>(k+5,-1));
        return solve(0,k);
    }
};