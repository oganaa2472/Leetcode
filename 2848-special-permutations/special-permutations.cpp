class Solution {
public:
    int MOD = 1e9 + 7;
    // memo[mask][last_idx]: mask төлөвт, хамгийн сүүлд last_idx тавигдсан үеийн боломжийн тоо
    int memo[1 << 14][14];

    int solve(int mask, int last_idx, const vector<int>& nums) {
        int n = nums.size();
        
        // 1. Base case: Бүх тоо ашиглагдсан бол 1 хүчинтэй дараалал бүрдлээ
        if (mask == (1 << n) - 1) {
            return 1;
        }

        // 2. Memoization шалгалт
        if (memo[mask][last_idx] != -1) {
            return memo[mask][last_idx];
        }

        long long ways = 0;

        // 3. Дараагийн ашиглагдаагүй тоо (nxt)-ийг сонгох
        for (int nxt = 0; nxt < n; nxt++) {
            // Хэрэв nxt тоо ашиглагдаагүй бол
            if ((mask & (1 << nxt)) == 0) {
                // Хуваагдах нөхцөлийг шалгана
                if (nums[last_idx] % nums[nxt] == 0 || nums[nxt] % nums[last_idx] == 0) {
                    ways = (ways + solve(mask | (1 << nxt), nxt, nums)) % MOD;
                }
            }
        }

        return memo[mask][last_idx] = ways;
    }

    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));

        long long total_permutations = 0;

        // Сэлгэмэлийн хамгийн эхний тоогоор тоо бүрийг туршиж үзнэ
        for (int i = 0; i < n; i++) {
            // i дэх тоог сонгосон тул mask = (1 << i), last_idx = i байна
            total_permutations = (total_permutations + solve(1 << i, i, nums)) % MOD;
        }

        return total_permutations;
    }
};