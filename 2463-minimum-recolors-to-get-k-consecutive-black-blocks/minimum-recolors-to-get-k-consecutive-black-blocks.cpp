class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b,w = 0;
        for(int i = 0;i<k;i++){
            if(blocks[i]=='W'){
                w++;
            }else{
                b++;
            }
        }
        int ans = w;
        for(int i =k;i<blocks.size();i++){
            if(blocks[i-k]=='W'){
                w--;
            }else{
                b--;
            }
            if(blocks[i]=='W'){
                w++;
            }else{
                b++;
            }
            ans = min(ans,w);
        }
        return ans;
    }
};