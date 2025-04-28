class Solution {
public:

string num;
int dp[10][10][2];  // dp[pos][count7][tight]

int digit_dp(int pos, int count1, bool tight) {
    if (pos == num.size()) return count1;  // 1 цифрийг агуулсан эсэх
    
    if (dp[pos][count1][tight] != -1) return dp[pos][count1][tight];

    int limit = tight ? (num[pos] - '0') : 9;  // Хамгийн их боломжит цифр
    int res = 0;

    for (int digit = 0; digit <= limit; digit++) {

        res += digit_dp(pos + 1, count1 + (digit == 1), tight && (digit == limit));
    }
  
    return dp[pos][count1][tight] = res;
}


    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        num = to_string(n);
        int upper = digit_dp(0, 0, 1);
        return upper;
    }  
};