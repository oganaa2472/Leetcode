#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    // memo[i][j] -> i-р индексээс эхлээд 3-т хуваахад j үлдэгдэл өгдөг хамгийн их нийлбэр
    std::vector<std::vector<int>> memo;
    const int INF = -1e9; // Боломжгүй утгыг тэмдэглэх маш бага тоо

    int solve(int i, int remainder, const std::vector<int>& nums) {
        // Баазын нөхцөл: Хэрэв массивын төгсгөлд хүрсэн бол
        if (i == nums.size()) {
            // Хэрэв үлдэгдэл 0 болж чадсан бол 0-ийг буцаана, үгүй бол боломжгүйг илтгэж INF буцаана
            return remainder == 0 ? 0 : INF;
        }

        // Хэрэв өмнө нь энэ төлөвийг тооцсон бол санамжаас шууд буцаана
        if (memo[i][remainder] != -1) {
            return memo[i][remainder];
        }

        // 1-р сонголт: Одоогийн тоог авахгүй алгасах
        int skip = solve(i + 1, remainder, nums);

        // 2-р сонголт: Одоогийн тоог авна. Үлдэгдлийг шинэчилнэ.
        // Математик утгаараа: (remainder - nums[i]) % 3-ийг эерэг байлгах үүднээс доорх хэлбэрээр бичнэ.
        int next_remainder = (remainder - (nums[i] % 3) + 3) % 3;
        int take = nums[i] + solve(i + 1, next_remainder, nums);

        // Хоёр сонголтын хамгийн ихийг нь санамжинд хадгална
        return memo[i][remainder] = std::max(skip, take);
    }

public:
    int maxSumDivThree(std::vector<int>& nums) {
        int n = nums.size();
        // Санамжийн массивыг -1-ээр дүүргэж бэлдэнэ. Багана нь дандаа 3 хэмжээтэй (0, 1, 2 үлдэгдэл)
        memo.assign(n, std::vector<int>(3, -1));

        // 0-р индекс болон 0 үлдэгдлээс эхлэн функцээ дуудна
        int result = solve(0, 0, nums);
        
        // Хэрэв хариу олоогүй бол (INF гарсан бол) 0-ийг буцаана
        return result < 0 ? 0 : result;
    }
};