class Solution {
public:
    unordered_map<int, bool> memo; // DP хадгалах сан
    int maxChoose, target;
    bool dfs(int state,int currentTotal){
        if(memo.count(state)) return memo[state];
        for (int i = 1; i <= maxChoose; i++) {
           if (!(state & (1 << (i - 1)))) {
            if (currentTotal + i >= target || !dfs(state | (1 << (i - 1)), currentTotal + i)) {
                    return memo[state] = true;
                }
            }
        }
        return memo[state] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxChoose = maxChoosableInteger;
        target = desiredTotal;

        int sum = (maxChoose * (maxChoose + 1)) / 2;
        if (sum < target) return false;
        if (target <= 0) return true;
        return dfs(0, 0);
    }
};