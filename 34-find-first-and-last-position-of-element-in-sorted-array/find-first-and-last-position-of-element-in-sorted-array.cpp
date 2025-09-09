
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirstPosition(nums, target), findLastPosition(nums, target)};
    }
    
    // Helper function to find the first position of target
    int findFirstPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int firstPosition = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If target is found, tentatively set firstPosition
            if (nums[mid] == target) {
                firstPosition = mid;
                // Move to the left part to check if there's an earlier occurrence
                right = mid - 1; 
            } else if (nums[mid] < target) {
                // Move right; target is greater
                left = mid + 1;
            } else {
                // Move left; target is smaller
                right = mid - 1;
            }
        }
        
        return firstPosition;
    }
    
    // Helper function to find the last position of target
    int findLastPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int lastPosition = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If target is found, tentatively set lastPosition
            if (nums[mid] == target) {
                lastPosition = mid;
                // Move to the right part to check if there's a later occurrence
                left = mid + 1;
            } else if (nums[mid] < target) {
                // Move right; target is greater
                left = mid + 1;
            } else {
                // Move left; target is smaller
                right = mid - 1;
            }
        }
        
        return lastPosition;
    }
};
