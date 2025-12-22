class Solution {
public:
    int mirrorDistance(int n) {
        string rev = to_string(n);
        reverse(rev.begin(), rev.end());
        int r = stoi(rev);
        return abs(n - r);
    }
};