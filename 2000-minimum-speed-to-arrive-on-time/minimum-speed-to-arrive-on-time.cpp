#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canReach(const vector<int>& dist, double hour, int speed) {
        double totalTime = 0.0;
        int n = dist.size();
        
        // Сүүлчийнхээс бусад галт тэрэгнүүдийн хугацаа (дээш тоймлогдоно)
        for (int i = 0; i < n - 1; i++) {
            totalTime += (dist[i] + speed - 1) / speed;
        }
        
        // Хамгийн сүүлийн галт тэрэг (хүлээх шаардлагагүй тул бутархай хэвээр үлдэнэ)
        totalTime += (double)dist[n - 1] / speed;
        
        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        
        // Эхний n - 1 галт тэрэг дор хаяж 1 цаг зарцуулах тул
        // нийт хугацаа n - 1-ээс их байх ёстой
        if (hour <= n - 1) {
            return -1;
        }

        int low = 1;
        int high = 1e7; // Бодлогын нөхцөлөөр хариу 10^7-оос хэтрэхгүй
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canReach(dist, hour, mid)) {
                ans = mid;
                high = mid - 1; // Бага хурдаар амжиж болох эсэхийг зүүн тийш шалгана
            } else {
                low = mid + 1;  // Хурд хүрэхгүй байгаа тул ихэсгэнэ
            }
        }

        return ans;
    }
};