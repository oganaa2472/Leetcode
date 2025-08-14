class Solution {
public:
    string largestGoodInteger(string num) {
        int maxValue= -1;
        string ans = "";
        int n = num.size();
        for (int i = 0;i<n-1;i++){
            if(num[i]==num[i+1]&&num[i]==num[i+2]){
                int ch = num[i] - '0';
                if(maxValue<ch){
                    ans ="";
                    ans+=num[i];
                    ans+=num[i+1];
                    ans+=num[i+2];
                    maxValue = ch;
                }
            }
        }
        return ans;
    }
};