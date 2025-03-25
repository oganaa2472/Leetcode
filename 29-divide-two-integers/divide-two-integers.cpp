class Solution {
public:
    int divide(int dividend, int divisor) {
        // IT IS maximum value of integer .
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;  // Хэрэв хуваагч нь -1 байвал хамгийн том утга авна
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;  // Хэрэв хуваагч нь -1 байвал хамгийн том утга авна
        }
        bool negative = (dividend < 0) != (divisor < 0);
        long long a = abs((long long)dividend); 
        long long b = abs((long long)divisor);
        int result = 0;


        while(a>=b){
            long long cnt = 0;
            //Бид битыг өндөр рүү шилжүүлэхэд хэд хэдэн удаа хуваах боломжтойг шалгана
            while(a>=(b<<(cnt+1))){
               cnt+=1;
            }
            a -= (b<<cnt);
            result += 1<<cnt;
        }
        return negative? -result : result;
    }
};