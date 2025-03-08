class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            if(n>=k+i){
                int c= 0;
                for(int j = i;j<k+i;j++){
                    if(blocks[j]=='W'){
                        c++;
                    }
                }
                ans = min(ans,c);
            }
            
        }
        return ans;
    }
};