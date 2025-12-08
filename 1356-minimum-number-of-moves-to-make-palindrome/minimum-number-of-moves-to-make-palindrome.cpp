class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int moves = 0;

        while (left < right) {
            // Хэрвээ хоёр талын тэмдэгт адил бол — OK
            if (s[left] == s[right]) {
                left++;
                right--;
            } 
            else {
                // Баруун талаас с[left]-тэй адил тэмдэгт хайна
                int i = right;
                while (i > left && s[i] != s[left]) {
                    i--;
                }

                // A) Олдсон (i != left)
                if (i != left) {
                    // i-г right руу ойртуулах swap-ууд
                    while (i < right) {
                        swap(s[i], s[i + 1]);
                        i++;
                        moves++;
                    }
                    left++;
                    right--;
                }
                // B) Олдоогүй → s[left] нь төвд очих ёстой тэмдэгт
                else {
                    swap(s[left], s[left + 1]);
                    moves++;
                }
            }
        }
        return moves;
    }
        
};