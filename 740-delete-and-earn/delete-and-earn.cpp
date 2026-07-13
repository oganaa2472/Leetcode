class Solution {
public:
    vector<int> points;
    vector<int> memo;
    int numPoints(int num) {
        
        if (num <= 0) return 0;
        
    
        if (memo[num] != -1) return memo[num];


        int skip = numPoints(num - 1);
        
        int take = points[num] + numPoints(num - 2);

        return memo[num] = std::max(skip, take);
    }
    int deleteAndEarn(vector<int>& nums) {
        
        if (nums.empty()) return 0;

        // Массив дахь хамгийн их тоог олно (үүгээр санамжийн хэмжээг тогтооно)
        int max_num = *std::max_element(nums.begin(), nums.end());
        
        // Массивын хэмжээг max_num + 1-ээр зарлана
        points.assign(max_num + 1, 0);
        memo.assign(max_num + 1, -1);

        // Тоо тус бүрийн нийт оноог тооцож хадгална
        for (int num : nums) {
            points[num] += num;
        }
        return numPoints(max_num);
    }
};