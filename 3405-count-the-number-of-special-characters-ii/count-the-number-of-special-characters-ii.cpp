class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> upper;
        unordered_map<char,int> lower;
        int n=word.size();
        for(int i = 0;i<n;i++){
            if(isupper(word[i]))
                upper[tolower(word[i])]++;
            else{
                if(upper.find((word[i]))==upper.end()){
                    lower[word[i]]++;
                }else{
                    lower.erase(word[i]);
                }
            }
        }
        int answer = 0;
        
        for (const auto& pair : lower) {
         char c = pair.first;
           
            if(upper.find(c)!=upper.end()){
                answer++;
            }
        }
    
        
        return answer;
    }
};