class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long MOD = 1e9 + 7;
        
        // a ба b-ийн ХБЕХ (LCM)-ийг олох
        long long lcm_val = std::lcm((long long)a, (long long)b);
        
        long long low = 1;
        long long high = (long long)n * min(a, b);
        long long ans = high;

        // Хариун дээр Хоёртын хайлт хийх
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // mid хүртэлх шидэт тоонуудын ширхгийг тоолох
            long long count = (mid / a) + (mid / b) - (mid / lcm_val);

            if (count >= n) {
                ans = mid;
                high = mid - 1; // Бага хариу байгаа эсэхийг шалгах
            } else {
                low = mid + 1;
            }
        }

        return ans % MOD;
    }
};