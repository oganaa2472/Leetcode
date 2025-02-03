class Solution {
public:
    vector<int> cost;
    unordered_map<int,string> dp; 
    string solve(int target){
        if (target == 0) return ""; 
        if (dp.count(target)) return dp[target]; 
        string answer="";
        for (int i = 8; i >= 0; --i) { 
            if (cost[i] <= target) { 
                string next = solve(target - cost[i]);
                if (next != "0" || target - cost[i] == 0) { 
                    string newstring = to_string(i + 1) + next;
                    if (newstring.size() > answer.size() || (newstring.size() == answer.size() && newstring > answer)) {
                        answer = newstring; 
                    }
                }
            }
        }

       
        return dp[target] = (answer.empty() ? "0" : answer);
    }
    string largestNumber(vector<int>& cost, int target) {
        this->cost=cost;
        string result = solve(target);
        return result == "0" ? "0" : result;
    }
};