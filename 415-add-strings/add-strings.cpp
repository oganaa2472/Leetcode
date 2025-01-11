class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";

        int carry = 0;

        int len1 = num1.size()-1;
        int len2 = num2.size()-1;

        while(len1>=0||len2>=0||carry){
            int dec1 = (len1>=0)?num1[len1]-'0':0;
            int dec2 = (len2>=0)?num2[len2]-'0':0;
            int sum = carry+dec1+dec2;
            carry = sum/10;
            res += (sum%10)+'0';
            len1--;
            len2--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};