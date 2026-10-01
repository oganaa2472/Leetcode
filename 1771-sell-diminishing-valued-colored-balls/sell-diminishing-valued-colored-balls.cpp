class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long long MOD = 1e9 + 7;

        // 1. Хайлтын мужаа тодорхойлох
        int low = 1;
        int high = 0;
        for (int count : inventory) {
            high = max(high, count);
        }

        // T: Бөмбөг бүрийг зарж буулгах хамгийн бага босго үнэ (Threshold)
        int T = 1;

        // 2. Binary Search on Answer:
        // mid болон түүнээс дээш үнэтэй бөмбөгнүүдийн тоо >= orders байх хамгийн их mid-ийг олно
        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long total_balls = 0;
            for (int count : inventory) {
                if (count >= mid) {
                    total_balls += (count - mid + 1);
                }
            }

            if (total_balls >= orders) {
                T = mid;          // mid үнээр хангалттай олон бөмбөг зарах боломжтой
                low = mid + 1;    // Илүү өндөр босго үнэ хайна
            } else {
                high = mid - 1;   // mid хэт өндөр байна, тоо нь хүрэхгүй
            }
        }

        // 3. Ашиг тооцоолох (Арифметик прогресс)
        long long total_profit = 0;
        long long sold_count = 0;

        // T + 1 болон түүнээс дээш үнэтэй бүх бөмбөгийг бүрэн зарна
        for (int count : inventory) {
            if (count > T) {
                long long n = count - T; // Зарагдах бөмбөгийн тоо
                // [T + 1, count] завсрын нийлбэр: n * (count + (T + 1)) / 2
                long long sum = n * (count + (T + 1LL)) / 2;
                total_profit = (total_profit + sum) % MOD;
                sold_count += n;
            }
        }

        // Үлдсэн (orders - sold_count) ширхэг бөмбөгийг яг T үнээр зарна
        long long remaining_orders = orders - sold_count;
        if (remaining_orders > 0) {
            total_profit = (total_profit + remaining_orders * T) % MOD;
        }

        return total_profit;
    }
};