#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        // dp[w] = w нийлбэрийг үүсгэхэд шаардагдах хамгийн цөөхөн үйлдлийн тоо
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;

        for (int x : nums) {
            // 0/1 Knapsack: багтаамжийг буурахаар давталт хийнэ
            for (int w = sum; w >= 0; --w) {
                if (dp[w] == INT_MAX) continue;

                // 1. Зөвхөн үржүүлэх эсвэл хэвээр үлдээх хувилбарууд
                int ops = 0;
                long long curr = x;
                while (w + curr <= sum) {
                    // Хэрэв curr-ийг нэмэхэд sum хэтрэхгүй бол DP-г шинэчилнэ
                    // Гэхдээ knapsack-ийн стандарт чиглэлээр буюу w-ээс sum руу явах эсвэл 
                    // доорх байдлаар гаднаас нь nums элемент бүрээр loop хийж болно.
                }
            }
        }

        // Үүнийг илүү хялбарр уламжлалт knapsack хэлбэрээр бичвэл:
        vector<int> f(sum + 1, 1e9);
        f[0] = 0;

        for (int x : nums) {
            for (int w = sum; w >= 0; --w) {
                // Элемент тус бүрийн хувьд үржүүлэх болон хуваах боломжуудыг шалгах
                // 1. Multiply sequence (or zero multiplication)
                int i = 0;
                long long y = x;
                while (y <= w) {
                    f[w] = min(f[w], f[w - y] + i);
                    ++i;
                    y <<= 1;
                }

                // 2. Division sequence
                i = 1;
                int val = x >> 1;
                while (val > 0) {
                    if (val <= w) {
                        f[w] = min(f[w], f[w - val] + i);
                    }
                    ++i;
                    val >>= 1;
                }
            }
        }

        return f[sum] > 500000 ? -1 : f[sum];
    }
};