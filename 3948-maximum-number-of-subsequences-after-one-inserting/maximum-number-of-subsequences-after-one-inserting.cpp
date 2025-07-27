class Solution {
public:
    long long numOfSubsequences(string s) {
        
        long long op1=0, op2=0, op3=0, ans=0;
        int n=s.length();

        vector<long long>pref(n,0), suff(n,0);
        for(int i=0;i<n;i++)
        {
            pref[i]=(s[i]=='L' ? 1 :0);
            suff[i]=(s[i]=='T' ? 1 :0);
        }

        for(int i=1;i<n;i++)
        {
            pref[i]+=pref[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suff[i]+=suff[i+1];
        }

        for(int i=0;i<n;i++)
        {
            if(s[i]=='C')
            {
                op1+=(pref[i]+1)*suff[i]; 
                op2+=pref[i]*(suff[i]+1); 
                ans+=pref[i]*suff[i]; 
            }
            else op3=max(op3,pref[i]*suff[i]); 
        }
        return max({op1,op2,ans+op3});
    }
};