class Solution {
public:
    vector<int> position,time;
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int i,int k,int curTime){
        if(i==n-1){
            return k>0?INT_MAX:0;
        }
        if(dp[i][k][curTime]!=-1) return dp[i][k][curTime];
        int ans = INT_MAX;
        int res = solve(i+1,k,time[i+1]);
        if(res!=INT_MAX){
            ans = min(ans,res+((position[i+1]-position[i])*curTime));
        }
        if(k>0){
            int timeSum = time[i+1];
            int operations = 0;
            for(int j = i+2;j<=min(n-1,i+k+1);j++){
                timeSum+=time[j];
                operations++;
                int res = solve(j,k-operations,timeSum);
                if(res!=INT_MAX){
                    ans = min(ans,res+((position[j]-position[i])*curTime)); 
                }
                
            }

        }
        return dp[i][k][curTime] = ans;
    }
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        this->n = n;
      dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(k+1, vector<int>(101, -1)));
        this->position = position;
        this->time = time;
        return solve(0,k,time[0]);
    }
};