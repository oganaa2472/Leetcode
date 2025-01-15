#include <bits/stdc++.h>
class Solution {
public:

    int minimizeXor(int num1, int num2) {
        int bit2 = __builtin_popcount(num2);
        int bit1 = __builtin_popcount(num1);
        int first = __builtin_clz(num1);
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
           if (num1&(1<<i)){
                ans += (1<<i);
                bit2--;
                if(bit2==0) break;   
           } 
        }
        int i = 0;
        if(bit2>0){
            while(bit2>0){
                if(!(ans&(1<<i))){
                   ans += (1<<i);
                   bit2--;
                }
                i++;
            }
        }

        return ans;
    }
};