class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
        int shift = 0;
        while(a<b){
            a>>=1;// right shift
            b>>=1;// right shift
            shift++;
        }
        return (a<<shift);
    }
};