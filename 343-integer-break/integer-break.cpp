class Solution {
public:

    int solve(int n,vector<int>& t){
        if(n==1) return 1;
        if(t[n]!=-1) return t[n]; 
        int ans = 0;
        for(int i = 1;i<n;i++)
        {
            ans=max({ans,i*(n-i),i*solve(n-i,t)});
        }
        return t[n]=ans;
    }
    int integerBreak(int n) {
        vector<int> t(59,-1);
        return solve(n,t);
    }
};