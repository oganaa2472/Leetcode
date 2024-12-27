class Solution {
public:
    int check(string s,int x, int op , char ch){
        for(auto it:s){
            if(it==ch){
                op--;
            }
            ch=ch^1;
        }
        return op>=0;
    }
    int solve(string s,int x, int op){
        if(x==1){
            return check(s,x,op,'1') || check(s, x, op, '0');
        }
        int cnt =1;
        int prev=-1;
        for(int i = 0;i<s.size();i++){
            if(s[i]==prev){
                cnt++;
            }
            else{
                op-=cnt/(x+1);
                cnt = 1;
                prev = s[i];
            }
        }
        op-=cnt/(x+1);
        return op>=0;
    }
    int minLength(string s, int numOps) {
        int n = s.size();
        int l = 1 ;
        int h = n;
        int ans = n;
        while(l<=h){
            int mid = (l+h)/2;
            if(solve(s,mid,numOps)){
                ans = mid;
                h = mid-1;
            }else {
                l = mid+1;
            }           
        }
        return ans;
    }
};