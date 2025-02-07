class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_result = 0;

   
        for (int num : nums) {
            xor_result ^= num;
        }

   
        int diff_bit = xor_result & (-xor_result);

        // 3. Хоёр бүлэгт хувааж XOR хийх
        int x = 0, y = 0;
        for (int num : nums) {
            if (num & diff_bit) {
                x ^= num;  // Бит нь 1 байгаа бүлэг
            } else {
                y ^= num;  // Бит нь 0 байгаа бүлэг
            }
        }

        return {x, y};
    }
};