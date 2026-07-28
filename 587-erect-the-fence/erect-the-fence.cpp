#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    // 3 цэгийн чиглэлийг тодорхойлох Vektor Cross Product функц
    int crossProduct(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 3) return trees; // 3 ба түүнээс цөөн цэгтэй бол бүгд хашаанд орно

        // Цэгүүдийг x, y координатаар эрэмбэлэх
        sort(trees.begin(), trees.end());

        vector<vector<int>> hull;

        // 1. Ниж хүрээ (Lower Hull) байгуулах
        for (int i = 0; i < n; ++i) {
            while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back(); // Баруун тийш эргэж байвал сүүлийн цэгийг хасна
            }
            hull.push_back(trees[i]);
        }

        // 2. Дээд хүрээ (Upper Hull) байгуулах
        int lower_hull_size = hull.size();
        for (int i = n - 2; i >= 0; --i) {
            while (hull.size() > lower_hull_size && crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        // Давхардсан цэгүүдийг арилгах
        set<vector<int>> unique_trees(hull.begin(), hull.end());
        
        return vector<vector<int>>(unique_trees.begin(), unique_trees.end());
    }
};