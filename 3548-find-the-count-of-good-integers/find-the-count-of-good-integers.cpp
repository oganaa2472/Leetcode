class Solution {
public:
    long long fact[12]={1};
    long long ans;
    unordered_map<string,int> vis;
    string generatePal(int num,int len){
        string s = to_string(num);
        string t = s.substr(0,len);
        reverse(t.begin(),t.end());
        return s + t;
    }
    long long check(string& palindrome){
        // cout<<palindrome<<endl;
        long long n = palindrome.size();
        if(n==1) return 1;
        vector<long long> p(10,0);
        for(int i = 0;i<palindrome.size();i++){
            long long cur = (palindrome[i]-'0');
            p[cur]++;
        }
        string s="";
        long long sum = fact[n];
        for(int i = 0;i<p.size();i++){
            long long cur = p[i];
            s += (cur+'a');
        }
        if(vis.find(s)!=vis.end()) return 0;
        vis[s]=1;
        for(int i =0;i<p.size();i++){
            if(p[i]!=0)
            sum = (sum / fact[p[i]]);
        }
        if(p[0]>0){
            long long againzero = fact[n-1];
            p[0]--;
            for(int i =0;i<p.size();i++){
                if(p[i]!=0)
                    againzero = (againzero / fact[p[i]]);
            }
            
            sum = sum - againzero;
        }
     
        return sum;
    }
    void find(int index,int num,int len,int k, int odd){
        if(index==len){

            if(odd==1){
                len--;
            }
            string genPal = generatePal(num,len);
            long long pal = stoll(genPal);
            if(pal%k==0){
                ans = ans + check(genPal);
            }
            return;
        }
            if(index==0){
                for(int i = 1;i<=9;i++){
                    int tnum = num*10+i;
                    find(index+1,tnum,len,k,odd); 
                }
            }else{
                for(int i = 0;i<=9;i++){
                   
                    int tnum = num*10+i;
                    find(index+1,tnum,len,k,odd); 
                }
            }
        return;
           
        
    }
    long long countGoodIntegers(int n, int k) {
        ans= 0;
        fact[1] = 1;
        vis.clear();
        for(int i =2;i<=11;i++){
            fact[i]=fact[i-1]*i;
        }

        if(n%2==0) {
            find(0,0,n/2,k,0);
        }
        else {
            // len = n/2+1;
            find(0,0,n/2+1,k,1);
        }
        
        return ans;
    }
};