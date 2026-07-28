class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;

            if (tx > ty) {
                // Хэрэв ty хэдийн симуляцийн эхний утгатай тэнцүү болсон бол
                // зөвхөн tx - sx нь ty-д хуваагддаг эсэхийг шалгана
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                // Хэрэв tx хэдийн симуляцийн эхний утгатай тэнцүү болсон бол
                if (tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        
        return false;
    }
};