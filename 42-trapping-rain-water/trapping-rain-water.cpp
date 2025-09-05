class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int leftMax = 0;
        int rightMax = 0;
        int result = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(leftMax<height[left]){
                    leftMax = height[left];
                }else{
                    result = result+(leftMax-height[left]);
                }
                left++;
            }else{
                if(height[right]>rightMax){
                    rightMax = height[right];
                }else{
                    result = result+(rightMax-height[right]);
                }
                right--;
            }
        }
        return result;


    }
};