class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        string k = "";
        int count = 1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(k.size()==0){
                count=1;
                k+=s[i];
            }
            else if(s[i]==k.back()){
                count++;
            }else if(s[i]!=k.back()){
                cout<<count<<" ";
                if(count%2==1){
                    ans++;
                    k.clear();
                }else{
                    k.clear();
                    count =1;
                    k = s[i];
                    
                }
    
                
                
            }
        }    
        return ans;  
    }
};