class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        map <char,int> mpp;
        for (char a : s) {
            mpp[a]++;
        }
        
        for (auto& p : mpp) {
            if (p.first == 'a') continue;
            int temp = abs(p.first - 'a');
            cnt = max(cnt, 26 - temp);
        }
        return cnt;
    }
};