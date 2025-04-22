const int mod = 1e9+7;
const int N = 1e4+5;

int dp[21][N];
int lengths[N][21];

class Solution {
    // lengths[j][k] --> How many unique paths are there that ends at 'j' & have length of 'k'
    void CalculateUniquePathLengths () {
        memset(lengths, 0, sizeof(lengths));

        for (int j = 1; j < N; j ++) {
            // contribute 'j' to its every multiples
            lengths[j][1] = 1;
            for (int k = j+j; k < N; k += j) {
                for (int i = 0; i < 20; i ++) lengths[k][i+1] += lengths[j][i];
            }
        }
    }
    
    // How many unique arrangement of length 'length' & having all the values from [1 ..X]
    int UniqueArrangements (int length, int mx) {
        if (length == 0) return (mx == 0);
        if (mx == 0) return 0;
        
        int &ans = dp[mx][length];
        if (ans != -1) return ans;
        
        ans = (UniqueArrangements(length-1, mx) + UniqueArrangements(length-1, mx-1)) % mod;
        return ans;
    }
    
public:
    int idealArrays(int n, int maxValue) {
        memset(dp, -1, sizeof(dp));
        CalculateUniquePathLengths();
        
        int ans = 0;
        for (int last = maxValue; last >= 1; last --) {            
            for (int j = 1; j < 21; j ++) {
                long long arrangementsWithEverything = UniqueArrangements(n, j);
                
                ans = (ans + (arrangementsWithEverything * lengths[last][j]) % mod) % mod;
            }
        }
        return ans;
    }
};