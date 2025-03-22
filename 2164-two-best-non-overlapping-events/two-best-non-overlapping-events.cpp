class Solution {
public:
    int n;
    vector<vector<int>> events;

    vector<vector<int>> dp;
    int upperBound(int i){
        int l = i+1;
        int r = events.size()-1;
        int nextIndex = events.size();

        while(l<=r){
            int mid = l+(r-l)/2;
            if(events[mid][0]>events[i][1]){
                nextIndex = mid;
                r = mid - 1;
            }else{
                l= mid+1;
            }
        }
        return nextIndex;
    }
    int solve(int i,int k){
    
        if(k==2 || i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];

        int nextIndex = upperBound(i);
     
        int inc  =events[i][2] + solve(nextIndex,k+1);
        int exc = solve(i+1,k);
        
        

        return dp[i][k] = max(exc,inc);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        n = events.size();
        this->events = events;
        dp.resize(n+1,vector<int>(3,-1));
        return solve(0,0);
    }
};