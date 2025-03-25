class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int d = 0;
        int k = max(start,goal);
        while(k){
            k>>=1;
            if((start&1)!=(goal&1)) d++;
            start>>=1;
            goal>>=1;
        }
        return d;
        

    }
};