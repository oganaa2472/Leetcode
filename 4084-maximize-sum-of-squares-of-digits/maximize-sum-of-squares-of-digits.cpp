class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum|| sum < 0 ) return "";
        string res;
        int i = 0;
        while(i<num){
        
            int d = min(9,sum);
            res.push_back('0'+d);
            sum = sum - d;
            i++;
        }
        if(sum!=0) return "";
        return res;
    }
};