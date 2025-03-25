class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int rowStart = 0,rowEnd = n-1;
        
        while(rowStart<rowEnd){
            int mid = rowStart+(rowEnd-rowStart)/2;
            if (matrix[mid][0] == target) {
                return true;
            }
             if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                rowStart = mid;
                break;
            }
            else if(matrix[mid][0]<target){
                rowStart = mid+1;
                
            }else{
                rowEnd = mid-1;
            }
        }
       
        int colStart = 0;
        int colEnd = matrix[0].size() - 1;

        while(colStart<=colEnd){
            int mid = colStart+(colEnd-colStart)/2;
            if(matrix[rowStart][mid]==target) return true;
            if(matrix[rowStart][mid]<target){
                colStart = mid+1;
            }else{
                colEnd = mid-1;
            }
        }
        return false;

    }
};