class Solution {
public:
    int n; 
    unordered_map<int, int> memo;

    int dp(vector<vector<int>>& stickersCount, string& target, int mask) {
        if (mask == (1 << n) - 1) return 0; 
        if (memo.count(mask)) return memo[mask];
        int res = INT_MAX;
        for (auto& sticker : stickersCount) {
            int new_mask = mask;
            vector<int> temp = sticker;

           
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0 && temp[target[i] - 'a'] > 0) {
                    new_mask |= (1 << i);
                    temp[target[i] - 'a']--;
                }
            }

            
            if (new_mask != mask) {
                int next = dp(stickersCount, target, new_mask);
                if (next != INT_MAX) {
                    res = min(res, 1 + next);
                }
            }
        }
        return memo[mask] = res;
    }

    int minStickers(vector<string>& stickers, string target) {
        n = target.size();

      
        vector<vector<int>> stickersCount;
        for (auto& sticker : stickers) {
            vector<int> count(26, 0);
            for (char c : sticker) count[c - 'a']++;
            stickersCount.push_back(count);
        }

        int answer = dp(stickersCount, target, 0);
        return answer == INT_MAX ? -1 : answer;
    }
};
