class Solution {
public:
    vector<vector<int>> dp;
    vector<int> tasks;
    int n, sessionTime;

    int solve(int mask, int remainingTime) {
        if (mask == (1 << n) - 1) return 0; 

        if (dp[mask][remainingTime] != -1) return dp[mask][remainingTime];

        int ans = n+1;
        for(int i = 0;i<n;i++){
           if ((mask & (1 << i)) == 0) { 
                if(remainingTime>=tasks[i]){
                    ans = min(ans,solve((1<<i)|mask,remainingTime-tasks[i]));
                }else{
                    ans = min(ans,1+solve((1<<i)|mask,sessionTime-tasks[i]));
                }
            }
        }
        return dp[mask][remainingTime] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        this->tasks = tasks;
        this->sessionTime = sessionTime;
        n = tasks.size();
        dp.assign(1 << n, vector<int>(sessionTime + 1, -1)); // Initialize DP
        return 1 + solve(0, sessionTime); // Start with a new session
    }
};
