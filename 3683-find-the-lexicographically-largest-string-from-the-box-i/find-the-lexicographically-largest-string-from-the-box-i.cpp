class Solution {
public:
    string answerString(string word, int numFriends) {
       
        if(numFriends==1) return word;
        char maxC = 'a';
        int n=word.size();
        vector<int> startIdx;
        for(int i = 0;i<n;i++){
            if(maxC<word[i]){
                startIdx.clear();
                maxC=word[i];
            }
            if(maxC==word[i]){
                startIdx.push_back(i);
            }
        }
        string ans = "";
        for(int i : startIdx){
            int endIdx = n - (numFriends-1-i);
            ans = max(ans,word.substr(i,endIdx-i));
        }
        return ans;

        
    }
};
