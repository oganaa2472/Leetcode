class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        long long digitSum = 0;
        int temp = n, length = 0;
        vector<int> count(10, 0);

        string s = to_string(n);
        length = s.length();
        for(char c : s) {
            int d = c - '0';
            count[d]++;
            digitSum += fact[d];
        }

        vector<int> targetCount(10, 0);
        int targetLength = 0;
        long long target = digitSum;
        if (target == 0) targetLength = 1, targetCount[0]++;
        while(target > 0) {
            targetCount[target % 10]++;
            target /= 10;
            targetLength++;
        }

        if(length != targetLength) return false;
        return count == targetCount;
    }
};