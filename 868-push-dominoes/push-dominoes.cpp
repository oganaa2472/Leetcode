class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> checkRight(n,0);
        for(int i = 0;i<n;i++){
            if(s[i]=='R'){
                right=1;
            }
            else if(s[i]=='.'){
                if(right>0){
                    checkRight[i]=right;
                    right++;
                }
            }else{
                right=0;
            }
        }
          for(int i = n;i>=0;i--){
            if(s[i]=='L'){
                left=1;
            }
            else if(s[i]=='.'){
                if(left>0&&checkRight[i]==0){
                    s[i]='L';
                }
                else if(left>0&&checkRight[i]>0){
                    
                    if(left>checkRight[i]){
                        s[i]='R';
                    }else if(left<checkRight[i]){
                        s[i]='L';
                    }
                    left++;
                    
                }
                else if(left==0&&checkRight[i]>0){
                    s[i]='R';
                }
            }
            else {
                left = 0;
            }
        }


        return s;
    }
};