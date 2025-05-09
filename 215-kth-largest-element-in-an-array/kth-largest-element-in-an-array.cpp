class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
    void median(vector<int>& nums,int left,int right){
        if(right-left<2) return;
        int mid = (left+right)/2;
        if(nums[left]>nums[mid]){
            swap(nums[left],nums[mid]);
        }
        if(nums[left]>nums[right]){
            swap(nums[right],nums[mid]);
        }
        if(nums[mid]>nums[right]){
            swap(nums[mid],nums[right]);
        }
    }
    int quickSelect(vector<int>& nums, int left, int right, int largest) {
        if (left == right) return nums[left];         
        median(nums,left,right);
        int pivot = partition(nums, left, right,largest);
        if (largest == pivot) {
            return nums[largest];
        } else if (largest <= pivot) {
            return quickSelect(nums, left, pivot - 1, largest);
        } else {
            return quickSelect(nums, pivot + 1, right, largest);
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivot) {
        int pivot_value = nums[pivot];
        swap(nums[pivot], nums[right]);
        int i = left-1;
        for (int j = left; j < right; ++j) {
            if (nums[j] < pivot_value) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[right], nums[i+1]);
        return i+1;
    }
};
