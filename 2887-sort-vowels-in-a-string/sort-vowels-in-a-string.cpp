class Solution {
public:
    static bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        else if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        else
            return false;
    }
    string sortVowels(string s) {
        vector<char> vowels;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
            }
        }
        int j = 0;
        sort(vowels.begin(),vowels.end());
        for(int i = 0;i<n;i++){
            if(isVowel(s[i])){
                s[i] = vowels[j++];
            }
        }         
        return s;

    }
};