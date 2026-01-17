class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        string answer = "";
        for(int i = 0;i<k;i++){
            answer += s[i];
        }
        reverse(answer.begin(),answer.end());
        for(int i = k;i<n;i++){
            answer+=s[i];
        }
        return answer;
    }
};