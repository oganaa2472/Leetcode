class Solution {
public:
    int n; // Самбарын хэмжээ
    int count = 0;

    vector<int> column; // Багана мөргөлдөхгүй эсэхийг шалгах
    vector<int> diag1;  // Гол диагональ мөргөлдөхгүй эсэх
    vector<int> diag2;  // Туслах диагональ мөргөлдөхгүй эсэх

    void search(int y) {
        // Бүх n хатан зөв байрлуулсан бол шийдлийг хадгална
        if (y == n) { 
            count++;
            return;
        }

        // Бүх баганыг шалгана
        for (int x = 0; x < n; x++) {
            if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) 
                continue; // Хэрэв мөргөлдөж байвал үргэлжлүүлнэ

            // Хатан байрлуулах
            column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;

            // Дараагийн мөр рүү шилжих
            search(y + 1);

            // Буцааж тохиргоог арилгах (Backtrack)
            column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
        }
    }
    int totalNQueens(int n) {
            this->n = n;


            // Массивуудыг анхны утгаар тохируулах
            column.assign(n, 0);
            diag1.assign(2 * n - 1, 0);
            diag2.assign(2 * n - 1, 0);
           

            // Backtracking хайлт эхлүүлэх
            search(0);

            return count;

    }
};