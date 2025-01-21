class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size()==1||s.size()==2) return true;
        int cnt = 0;
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                i++;
                cnt++;
                break;
            }
        }
        int tempi = i-1;
        int tempj = j-1;

        int cnt1 = cnt;

        while(tempi<tempj){
            if(s[tempi]==s[tempj]){
                tempj--;
                tempi++;
            }else{
                cnt1++;
                break;
            }

        }
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }else{
                cnt++;
                break;
            }
        }
        int answer = min(cnt,cnt1);
        if(answer>=2) return false;
        return true;
    }
};