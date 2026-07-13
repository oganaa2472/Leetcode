class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int res = 1;
        
        // Тоог 4-өөс их байх хугацаанд 3-ыг тасдаж авч үржүүлсээр байна
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        
        // Үлдсэн хэсгийг (2, 3, эсвэл 4) шууд үржүүлнэ
        res *= n;
        
        return res;
    }
};