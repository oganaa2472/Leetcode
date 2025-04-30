class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k_smallest) {
        if (left == right) return nums[left];  

       
        srand(time(0));
        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(nums, left, right, pivot_index);

        if (k_smallest == pivot_index) {
            return nums[k_smallest];
        } else if (k_smallest < pivot_index) {
            return quickSelect(nums, left, pivot_index - 1, k_smallest);
        } else {
            return quickSelect(nums, pivot_index + 1, right, k_smallest);
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivot_index) {
        int pivot_value = nums[pivot_index];
        swap(nums[pivot_index], nums[right]); // Move pivot to end
        int store_index = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot_value) {
                swap(nums[store_index], nums[i]);
                store_index++;
            }
        }

        swap(nums[right], nums[store_index]); // Move pivot to final place
        return store_index;
    }
};
