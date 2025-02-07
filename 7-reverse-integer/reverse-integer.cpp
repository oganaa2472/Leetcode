class Solution {
public:
    int reverse(int x) {
        long long original = x;
        if(original<0){
            original=original*-1;
        }
        
        string strX = to_string(original);
        std::reverse(strX.begin(), strX.end());
        long long res = stoll(strX); 
        if(x<0) res*=-1;
        if (res < -(1LL << 31) || res > (1LL << 31) - 1) {
            return 0;
        }
        
        return static_cast<int>(res);
    }
};