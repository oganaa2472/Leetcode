class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        int each_square = 1;
        for(int i = 1;i<=n;i++){
            if(each_square*2==i){
                each_square = each_square*2;
            }
            dp[i] = dp[i-each_square]+1;
        }
        return dp;
    }
};