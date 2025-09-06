class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size()-1;
        while(left<right){
            for(int i = 0;i<right-left;i++){
               int topLeft = matrix[left][left+i];
               int topRight = matrix[left+i][right];
               int bottomRight = matrix[right][right-i];
               int bottomLeft = matrix[right-i][left];
               matrix[left][left+i] = bottomLeft;
               matrix[left+i][right] = topLeft;
               matrix[right][right-i] = topRight;
               matrix[right-i][left] = bottomRight;

            }
            left++;
            right--;
        }
    }

};