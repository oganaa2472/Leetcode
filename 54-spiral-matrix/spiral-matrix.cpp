class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> answer;
        if(matrix.empty()) return answer;
        
        int top = 0; // Initialize the top boundary
        int bottom = matrix.size() - 1; // Initialize the bottom boundary
        int left = 0; // Initialize the left boundary
        int right = matrix[0].size() - 1; // Initialize the right boundary
        
        while(top <= bottom && left <= right) {
            // 00,01,02
            for(int i = left;i<=right;i++){
                answer.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<=bottom;i++){
                answer.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom) {
                 for(int i = right;i>=left;i--){
                    answer.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
           
            if(left <= right) {
                // Traverse from bottom to top along the current left boundary
                for(int i = bottom; i >= top; --i) {
                    answer.push_back(matrix[i][left]);
                }
                ++left; // Move the left boundary rightwards
            }
        }
        return answer;
    }
    
};