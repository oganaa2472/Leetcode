class Solution {
public:

    int n; // Самбарын хэмжээ
    vector<vector<string>> solutions; // Бүх боломжит шийдлүүд

    vector<int> column; // Багана мөргөлдөхгүй эсэхийг шалгах
    vector<int> diag1;  // Гол диагональ мөргөлдөхгүй эсэх
    vector<int> diag2;  // Туслах диагональ мөргөлдөхгүй эсэх
    vector<string> board;
    void search(int y) {
    // Бүх n хатан зөв байрлуулсан бол шийдлийг хадгална
    if (y == n) { 
        solutions.push_back(board); 
        return;
    }

        // Бүх баганыг шалгана
        for (int x = 0; x < n; x++) {
            if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) 
                continue; // Хэрэв мөргөлдөж байвал үргэлжлүүлнэ

            // Хатан байрлуулах
            board[y][x] = 'Q';
            column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;

            // Дараагийн мөр рүү шилжих
            search(y + 1);

            // Буцааж тохиргоог арилгах (Backtrack)
            board[y][x] = '.';
            column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        solutions.clear();

        // Массивуудыг анхны утгаар тохируулах
        column.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);
        board.assign(n, string(n, '.'));

        // Backtracking хайлт эхлүүлэх
        search(0);

        return solutions;
    }
};