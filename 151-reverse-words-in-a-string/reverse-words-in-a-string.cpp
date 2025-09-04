class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while(iss>>word){
            words.push_back(word);
        }
        int left = 0;
        int right = words.size()-1;
        while(left<right){
            swap(words[left++],words[right--]);
        }
        string result;
        for(auto& str:words){
            if(!result.empty()){
                result+=" ";
            }
            result+=str;
        }
        return result;
    }
};