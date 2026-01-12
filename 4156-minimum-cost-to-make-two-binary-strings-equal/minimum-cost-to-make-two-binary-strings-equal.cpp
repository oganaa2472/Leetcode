class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();
        int count01 = 0, count10 = 0;

        // 1. Ялгаатай битүүдийг тоолох
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (s[i] == '0' && t[i] == '1') count01++;
                else count10++;
            }
        }
        long long totalCost = 0;

        // 2. Хоёр ялгаатай битийг хооронд нь тааруулах боломжтой бол swap ашиглах
        int pairs = min(count01, count10);

        long long pairCost = pairs * min(2LL*flipCost,swapCost*1LL);

        int remain = abs(count01-count10);

        long long half = remain/2LL * min(2LL*flipCost,1LL*swapCost+crossCost);

        long long oddCost = remain%2LL * flipCost;
        return pairCost+ half+oddCost;

        
    }
};