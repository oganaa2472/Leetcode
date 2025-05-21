class Solution {
public:
    pair<int,int> getCoordinates(int square,int n){
        int r_c = square-1;
        int row_from_bottom = r_c/n;
        int row = n - 1 - row_from_bottom;
        int col;
        if(row_from_bottom%2== 0 ){
            col = r_c%n;
        }else{
            col = n - 1 - (r_c%n);
        }
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int totalSquares = n * n;

        queue<pair<int,int>> q; // {current_square,moves_made}
        unordered_map<int,bool> visited;
        q.push({1,0});
        visited[1] = true;
        while(!q.empty()){
            auto [currentSquare,moves] = q.front();
            q.pop();
            if(currentSquare==totalSquares) return moves;
            for(int dice = 1;dice<=6;dice++){
                int nextSquare = currentSquare + dice;
                if(nextSquare>totalSquares)continue;
                auto [r,c] = getCoordinates(nextSquare, n);
                int actualNextSquare = nextSquare;
                if(board[r][c]!=-1){
                    actualNextSquare = board[r][c];
                } 
                if(!visited[actualNextSquare]){
                    visited[actualNextSquare] = true;
                    q.push({actualNextSquare, moves + 1});
                }
            }
        }
        return -1;
    }
};