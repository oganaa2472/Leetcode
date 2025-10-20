class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long i = 1;

        while (n) {
            int x = n % 10;
            if (x > 0) {
                x = x * i;
                res.insert(res.begin(), x);  // push at front
            }
            i = i * 10;
            n = n / 10;
        }
        return res;
    }
};