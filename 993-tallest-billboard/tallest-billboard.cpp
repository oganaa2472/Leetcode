class Solution {
public:
    unordered_map<string, int> memo;
    int ans,n;
    vector<int> rods;
    int solve(int i, int s1) {
        if (i == n) {
            if(s1==0) return 0;
            return INT_MIN;
        }
        
        string key = to_string(i) + "," + to_string(s1);
        if (memo.count(key)) return memo[key];

        int res = solve(i+1, s1);

        res = max(res, rods[i]+solve(i+1, s1+rods[i]));
        res = max(res, solve(i+1,s1-rods[i]));
        return memo[key] = res;
    }

    int tallestBillboard(vector<int>& rods) {
        this->rods = rods;
        n = rods.size();
        int ans = solve(0, 0);
        if (ans < 0)return 0;
        else return ans;
    }
};
