class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<char,string> row;
        unordered_map<char,string> col;
        unordered_map<char,string> mid;   
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='.') continue;
                int midIndex =3*(i/3)+j/3;
                string a = row[i];
                string b = col[j];
                string c = mid[midIndex];
                if(a.find(board[i][j])!=string::npos||
                b.find(board[i][j])!=string::npos
                ||c.find(board[i][j])!=string::npos
                ) return false;
                col[j] += board[i][j];
                row[i] += board[i][j];
                mid[midIndex] += board[i][j];
            }
            // cout<<endl;
        }
        return true;
    }
};