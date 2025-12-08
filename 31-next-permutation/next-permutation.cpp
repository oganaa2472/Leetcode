class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
        int i = n - 2;

    // 1️⃣ Баруун талаас өсөхгүй эхний индексийг хай
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            // 2️⃣ i-аас баруун талын хэсгээс i-аас том хамгийн жижиг элементийг хай
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;

            // 3️⃣ Swap хийх
            swap(nums[i], nums[j]);
        }

        // 4️⃣ i+1 → end-ийг reverse хийх
        reverse(nums.begin() + i + 1, nums.end());
    }
};