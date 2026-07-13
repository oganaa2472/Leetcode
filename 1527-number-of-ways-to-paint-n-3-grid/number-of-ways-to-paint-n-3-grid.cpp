class Solution {
public:
    int numOfWays(int n) {
        long long MOD = 1e9 + 7;
        
        // 1-р мөрний суурь утгууд
        long long aba = 6;
        long long abc = 6;
        
        // 2-р мөрнөөс n-р мөр хүртэл давтана
        for (int i = 2; i <= n; ++i) {
            long long prev_aba = aba;
            long long prev_abc = abc;
            
            // Шилжилтийн томьёо
            aba = (3 * prev_aba + 2 * prev_abc) % MOD;
            abc = (2 * prev_aba + 2 * prev_abc) % MOD;
        }
        
        // Нийт боломж нь хоёр хэв маягийн нийлбэр байна
        return (aba + abc) % MOD;
    }
};