class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int i = 0;
        int j = height.size()-1;

        while(i<j){
            
            int k = (j-i)*min(height[i],height[j]);
            answer = max(answer,k);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return answer;
    }
};