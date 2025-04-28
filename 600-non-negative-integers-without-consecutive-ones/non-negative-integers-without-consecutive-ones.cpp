class Solution {
public:
    int dp[32][2][3];
    int n = 32;
    string num;
    int solve(int pos,int tight,int prev){
        if (pos == 32) {
        return 1; // We have successfully formed one valid binary number
    }

    // Memoization: If the state has been computed, return the stored result
    if (dp[pos][tight][prev] != -1) {
        return dp[pos][tight][prev];
    }

    int res = 0; // Result for the current state
    // The limit for the current digit (0 or 1)
    // If tight is true, the limit is the digit at the current position in num_binary
    // If tight is false, the limit is always 1 (we can place 0 or 1)
    int limit = tight ? (num[pos] - '0') : 1;

    // Iterate through possible digits (0 or 1) for the current position
    for (int digit = 0; digit <= limit; digit++) {
        // Check the constraint: no two adjacent ones
        // If the previous digit was 1 (prev == 1) AND the current digit is 1 (digit == 1), skip.
        // The initial state prev == 2 does not impose a constraint.
        if (prev == 1 && digit == 1) {
            continue;
        }

        // Calculate the next tight state
        // It remains tight only if it was tight AND we chose the limit digit
        bool next_tight = tight && (digit == limit);

        // Calculate the next previous digit state
        // If the current digit is 0, the next previous digit is 0.
        // If the current digit is 1, the next previous digit is 1.
        // The initial state 2 is only used at the very beginning.
        int next_prev = digit;

        // Recursively call for the next position
        res += solve(pos + 1, next_tight, next_prev);
    }

    // Store and return the result
    return dp[pos][tight][prev] = res;

    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        num = bitset<32>(n).to_string();
        return solve(0,true,2);
    }
};