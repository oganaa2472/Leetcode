class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        long long k = 0;
        long long ans = 1;
        for(int i = 2;i<=n;i++)
        {
            k+=4;
            ans=ans+k;
        }
        return ans;
    }
};