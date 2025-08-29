class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign=0;
        long long ans=0;
        while(s[i] == ' ') i++;

        if(s[i] == '-') { 
            sign = 1;
            i++;
        } else if(s[i] == '+') {
            sign = 0;
            i++;
        }
        while(s[i] == '0') i++;

        while(s[i] >= '0' && s[i] <= '9') {
            if(ans > INT_MAX) {
                if(sign) return INT_MIN;
                return INT_MAX;
            }
            ans = ans * 10 + s[i] - '0';
            i++;
        }
        if(sign){
            ans=ans*-1;
        }
        
        // Handle overflow/underflow
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        
        return (int) ans;
        
    }
};