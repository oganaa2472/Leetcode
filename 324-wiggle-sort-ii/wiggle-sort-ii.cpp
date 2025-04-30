class Solution {
public:

 void quickSelect(vector<int>& nums, int left, int right, int k_smallest) {
        if (left >= right) return;

        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(nums, left, right, pivot_index);

        if (k_smallest == pivot_index)
            return;  // k-th smallest is in place
        else if (k_smallest < pivot_index)
            quickSelect(nums, left, pivot_index - 1, k_smallest);
        else
            quickSelect(nums, pivot_index + 1, right, k_smallest);
    }

    int partition(vector<int>& nums, int left, int right, int pivot_index) {
        int pivot_value = nums[pivot_index];
        swap(nums[pivot_index], nums[right]);
        int store_index = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot_value) {
                swap(nums[store_index], nums[i]);
                store_index++;
            }
        }

        swap(nums[store_index], nums[right]);
        return store_index;
    }

    vector<int> findKthSmallestAndReturnList(vector<int>& nums, int k) {
        quickSelect(nums, 0, nums.size() - 1, k - 1);  // k-th smallest at index k-1
        return nums;
    }

    void wiggleSort(vector<int>& nums) {
        // nums = findKthSmallestAndReturnList(nums,nums.size()/2);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> arr(n,0);
        int j = 0;
        for (int i = n - 1; i >= n / 2; --i) {
        if (j < n) arr[j] = nums[i - n/2];  // left side (optional if you need)
        if (j + 1 < n) arr[j + 1] = nums[i];  // right side
            j += 2;
        }

        if (n % 2 == 1) arr[n - 1] = nums[0]; // middle element (if odd)
        nums = arr;


        // int n = nums.size();
        // for(int i = 1;i<n/2;i=i+2){
        //     swap(nums[i],nums[nums.size()-1-i]);
        // }
        // nums = findKthSmallestAndReturnList(nums,nums.size()/2);
    }
};