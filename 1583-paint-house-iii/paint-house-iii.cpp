#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int memo[101][101][21];
    const int INF = 1e9; // Залруулж боломжгүй төлөвийг илэрхийлэх том тоо

    int solve(int i, int target_left, int prev_color, int m, int n, vector<int>& houses, vector<vector<int>>& cost) {
        // Хөршийн тоо сөрөг болбол боломжгүй
        if (target_left < 0) return INF;
        
        // Бүх байшинг будаж дууссан үед
        if (i == m) {
            return target_left == 0 ? 0 : INF;
        }

        // Кэшлэгдсэн утга байвал шууд буцаана
        if (memo[i][target_left][prev_color] != -1) {
            return memo[i][target_left][prev_color];
        }

        int min_cost = INF;

        // Тохиолдол 1: Байшин аль хэдийн будагдсан
        if (houses[i] != 0) {
            int cur_color = houses[i];
            int new_target = target_left - (cur_color != prev_color ? 1 : 0);
            min_cost = solve(i + 1, new_target, cur_color, m, n, houses, cost);
        } 
        // Тохиолдол 2: Будагдаагүй тул бүх өнгөөр будаж үзнэ
        else {
            for (int color = 1; color <= n; ++color) {
                int new_target = target_left - (color != prev_color ? 1 : 0);
                int current_cost = cost[i][color - 1] + solve(i + 1, new_target, color, m, n, houses, cost);
                min_cost = min(min_cost, current_cost);
            }
        }

        return memo[i][target_left][prev_color] = min_cost;
    }

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // memo хүснэгтийг -1-ээр зааглан эхлүүлнэ
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 101; ++j)
                for (int k = 0; k < 21; ++k)
                    memo[i][j][k] = -1;

        int ans = solve(0, target, 0, m, n, houses, cost);
        return ans >= INF ? -1 : ans;
    }
};