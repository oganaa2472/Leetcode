class Solution {
public:

    int n,x; 
    int mod = 1e9+7;
    int power(int a,int x){
        int result = 1;
        while(x>0){
            if(x%2==1) result*=(a)%mod;
            a = (a%mod * a%mod)%mod;
            x=x/2;
        }
        return result%mod;
    }
    unordered_map<int,unordered_map<int,int>> dp;
    int solve(int i, int s){
        // cout<<s<<" "<<i<<endl;
        if(i>n||s+power(i,x)>n){
            return 0;
        }
        if(s+power(i,x)==n) return 1;

        if(dp[i][s+power(i,x)]!=0) return dp[i][s+power(i,x)];

        int include = solve(i+1,s+power(i,x));
        int exclude = solve(i+1,s);
        return dp[i][s+power(i,x)] = (include+exclude)%mod;

    }
    int numberOfWays(int n, int x) {
        this->n=n;
        this->x=x;
        int answer = solve(1,0);
        return answer;
    }
};