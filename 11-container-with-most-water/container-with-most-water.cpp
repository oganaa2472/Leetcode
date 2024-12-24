class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n -1;
        int answer = 0 ;
        while(i<j){
            answer = max(answer,(j-i)*min(height[i],height[j]));
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return answer;
    }
};