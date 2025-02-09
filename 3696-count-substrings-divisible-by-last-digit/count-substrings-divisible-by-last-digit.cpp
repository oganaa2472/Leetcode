class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        int mod9[9] {}, mod7[7] {}, tmp[9] {};

        auto addMod9 = [&](int add) {
            for(int i = 0; i < 9; i++) {
                tmp[(i + add) % 9] = mod9[i];
            }
            copy(tmp, tmp + 9, mod9);
        };
        auto addDigitMod7 = [&](int digit) {
            fill(tmp, tmp + 7, 0);
            for(int i = 0; i < 7; i++) {
                tmp[(10*i + digit) % 7] = mod7[i];
            }
            copy(tmp, tmp + 7, mod7);
        };

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int num = s[i]-'0';
            if(num > 0) {
                ans++;
                if(num == 1 || num == 2 || num == 5) {
                    ans += i;
                }else if(num == 3 || num == 6) {
                    ans += mod9[0] + mod9[3] + mod9[6];
                }else if(num == 4) {
                    if(i > 0) {
                        int last2 = 10*(s[i - 1]-'0') + num;
                        if(last2 % 4 == 0) ans += i;
                    }
                }else if(num == 7) {
                    ans += mod7[0];
                }else if(num == 8) {
                    if(i > 0) {
                        int last2 = 10*(s[i - 1]-'0') + num;
                        if(last2 % 8 == 0) ans++;
                        if((i - 2) >= 0) {
                            int last3 = 100*(s[i - 2]-'0') + last2;
                            if(last3 % 8 == 0) ans += i-1;
                        }
                    }
                }else if(num == 9) {
                    ans += mod9[0];
                }
            }
            addMod9(num);
            addDigitMod7(num);
            mod9[num % 9]++, mod7[num % 7]++;
        }
        return ans;
    }
};