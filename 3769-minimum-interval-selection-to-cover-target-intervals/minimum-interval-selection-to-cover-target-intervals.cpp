class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals,
                     vector<vector<int>>& targetIntervals) {

        // Input-ийг хадгалах
        auto vocaborago =
            make_pair(availableIntervals, targetIntervals);

        auto available = vocaborago.first;
        auto target = vocaborago.second;

        if (target.empty()) return 0;

        // 1. Target интервалуудыг эрэмбэлэх
        sort(target.begin(), target.end());

        // 2. Давхцаж эсвэл шүргэлцэж буй target-уудыг нэгтгэх
        vector<vector<int>> merged;

        for (auto& t : target) {
            if (merged.empty() ||
                t[0] > merged.back()[1]) {
                merged.push_back(t);
            } else {
                merged.back()[1] =
                    max(merged.back()[1], t[1]);
            }
        }

        // 3. Available интервалуудыг зүүн захаар эрэмбэлэх
        sort(available.begin(), available.end());

        priority_queue<int> pq;
        int j = 0;
        int ans = 0;

        // 4. Target-ийн бүрхэгдээгүй хэсгүүдийг Greedy-ээр бүрхэх
        for (int i = 0; i < (int)merged.size(); ) {
            int x = merged[i][0];

            // Өмнөх интервал энэ target-ийн хэсгийг бүрхсэн бол
            // бүрхэгдээгүй хамгийн зүүн цэг рүү шилжинэ.
            // x нь өмнөх хүрэлтээс эхэлж байж болно.
            if (i > 0) {
                // Энэ салааг доорх while-ийн дараах
                // хүрэлтээр удирдах тул тусгай үйлдэл шаардлагагүй.
            }

            while (j < (int)available.size() &&
                   available[j][0] <= x) {
                pq.push(available[j][1]);
                j++;
            }

            while (!pq.empty() && pq.top() < x) {
                pq.pop();
            }

            if (pq.empty()) return -1;

            int reach = pq.top();

            if (reach == x && x < merged[i][1]) {
                return -1;
            }

            ans++;

            // Сонгосон интервалын хүрсэн цэг хүртэл урагшлах
            while (i < (int)merged.size() &&
                   merged[i][1] <= reach) {
                i++;
            }

            if (i < (int)merged.size() &&
                merged[i][0] <= reach) {
                // Одоогийн target-ийн үлдсэн хэсэг
                // reach цэгээс цааш үргэлжилж байна.
                merged[i][0] = reach;
            }
        }

        return ans;
    }
};