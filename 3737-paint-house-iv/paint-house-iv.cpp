
typedef long long ll;
class Solution {
public:
    
    // 4 green, red, blue 
    vector<int> colors{1,2,3};
    long long solve(int index,vector<vector<int>>& cost,int prev1,int prev2,vector<vector<vector<long long>>>&dp){
        int n = cost.size();
        if(cost.size()/2<=index){
            return 0;
        }
        if(dp[index][prev1][prev2]!=-1){
            return dp[index][prev1][prev2];
        }
        long long result = LLONG_MAX;
        for(int i = 0;i<3;i++){
            for(int k = 0;k<3;k++){
                if(colors[i]!=colors[k]&&colors[i]!=prev1&&colors[k]!=prev2){
                    result = min(
                        result,cost[index][colors[i]-1]+ cost[n-index-1][colors[k]-1]
                        +
                        solve(index+1,cost,colors[i],colors[k],dp)
                    );
                }
            }
        }
        return dp[index][prev1][prev2] = result;
    }

int n;
vector<vector<int>> cost;
ll memo[50000+1][4][4]; // Assuming n is up to 100, so pairs are up to 50. 4 for prev_left and prev_right (0-2 and 3 for initial state)

ll dp(ll i, ll prev_left, ll prev_right) {
    if (i == n / 2) {
        return 0;
    }
    if (memo[i][prev_left][prev_right] != -1) {
        return memo[i][prev_left][prev_right];
    }

    ll min_cost = LLONG_MAX;

    for (int cl = 0; cl < 3; ++cl) {
        for (int cr = 0; cr < 3; ++cr) {
            if (cl == cr) continue; // Current pair must have different colors

            if (i > 0) {
                // Check against previous pair's left and right
                if (cl == prev_left || cr == prev_right) continue;
            }

            ll current_cost = cost[i][cl] + cost[n - 1 - i][cr];
            ll next_cost = dp(i + 1, cl, cr);

            if (next_cost == INT_MAX) continue; // Skip if next_cost is not possible

            if (current_cost + next_cost < min_cost) {
                min_cost = current_cost + next_cost;
            }
        }
    }

    return memo[i][prev_left][prev_right] = (min_cost == INT_MAX ? INT_MAX : min_cost);
}

    long long minCost(int n, vector<vector<int>>& cost) {
        // vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(4,vector<long long>(4,-1)));
        // int prev2 = n-(0+1);
        // return solve(0,cost,0,0,dp);
        this->n = n;
        this->cost = cost;
        memset(memo, -1, sizeof(memo));
        ll result = dp(0, 3, 3); // Start with invalid prev colors (3) for the first pair
        return (ll)result == LLONG_MAX ? -1 : result;
    }
   
};