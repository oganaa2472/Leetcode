class Solution {
public:
    vector<int> num;
    int dp[24][407][2];
    
    int mx,mn;
    const int mod = 1e9+7;
    int solve(int idx,int sum,int f){
        if(idx == num.size()){
            if(sum>=mn && sum<=mx){
                return 1;
            }
            return 0;
        }
            
        int &x = dp[idx][sum][f];
        if(x !=-1)return x;
        
        int lim = f?9:num[idx];
        
        int ans = 0;
        for(int i = 0;i<=lim;i++){
            int nwF = f?f:i<lim;
            
            ans+=solve(idx+1,sum+i,nwF);
            ans%=mod;
        }
        return x = ans;
    }
    
    int solveR(string lim){
        num.clear();
        for(auto c:lim){
            num.push_back(c-'0');
        }        
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
    
    string rest(string num){
        int id = num.size()-1;
        while(id>=0 && num[id]=='0'){
            num[id] = '9';
            id--;
        }
        if(id == 0)return num.substr(1);
        num[id]--;
        return num;
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        mx = max_sum;
        mn = min_sum;
        
        int R = solveR(num2);   
        if(rest(num1)=="")return R;
        int L = solveR(rest(num1));
        R-=L;
        if(R<0)R+=mod;
        return R;
    }
};