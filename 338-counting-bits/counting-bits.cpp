class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i = 0;i<=n;i++){
            result[i] = __popcount(i);
        }
        return result;
    }
};