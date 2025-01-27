class Solution {
public:
    bool isCheck(int end,int start,int count,int k){
        return end+1-start-count<=k;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,bool> letters;
        for(char& c:s){
            letters[c]=true;
        }

        int answer = 0;
        for(auto [letter,x]:letters){
            int start=0;

            int count = 0;
            for(int end = 0;end<s.size();end++){
                if(s[end]==letter){
                    count++;
                }
                while(!isCheck(end,start,count,k)){
                    if(s[start]==letter){
                        count--;
                    }
                    start++;
                }
                answer = max(answer,end+1-start);
            }
        
        }
        return answer;
    }
};