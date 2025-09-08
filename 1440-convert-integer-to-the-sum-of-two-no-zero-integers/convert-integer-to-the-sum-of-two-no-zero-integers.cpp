class Solution {
public:
    bool isNoZero(int num) {
        int x = num;
        while (x != 0) {
            if (x % 10 == 0) {
                return false;
            }
            x /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> vec(2);
        for(int i = 1;i<n;i++){
            if(isNoZero(i)&&isNoZero(n-i)){
                vec[0] = i;
                vec[1] = n-i;
            }
        }
        return vec;
    }
};