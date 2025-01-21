class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        string answer;
        while (i < n && j < m) {
            answer += word1[i++];
            answer += word2[j++];
        }      
        while (i < n) {
            answer += word1[i++];
        }
        while (j < m) {
            answer += word2[j++];
        }
        return answer;
    }
};