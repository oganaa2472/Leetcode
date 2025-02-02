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
    // unordered_map<int,unordered_map<int,int>> dp;
    int solve(int i, int s,vector<vector<int>>&memo){
        // cout<<s<<" "<<i<<endl;
        if(i>n||s+power(i,x)>n){
            return 0;
        }
        if(s+power(i,x)==n) return 1;

        if(memo[i][s+power(i,x)]!=-1) return memo[i][s+power(i,x)];

        int include = solve(i+1,s+power(i,x),memo);
        int exclude = solve(i+1,s,memo);
        return memo[i][s+power(i,x)] = (include+exclude)%mod;

    }
    int numberOfWays(int n, int x) {
        this->n=n;
        this->x=x;
        vector<vector<int>> memo(
            n,
            vector<int>(n,-1));
        int answer = solve(1,0,memo);
        return answer;
    }
};