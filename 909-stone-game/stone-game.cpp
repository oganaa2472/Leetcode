class Solution {
public:
    unordered_map<string, int> memo;
    int dp(int i, int j, vector<int>& piles) {
            if (i == j) {
                return piles[i];
            }
            string key = to_string(i) + "," + to_string(j);
            
           
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }
            
           
            int chooseFirst = piles[i] - dp(i + 1, j, piles);
            int chooseLast = piles[j] - dp(i, j - 1, piles);
            
            memo[key] = max(chooseFirst, chooseLast);
            
            return memo[key];
        }
    
    bool stoneGame(vector<int>& piles) {
    

        int n = piles.size();
    
        int difference = dp(0, n - 1, piles);
   
        return difference > 0;

    }
};