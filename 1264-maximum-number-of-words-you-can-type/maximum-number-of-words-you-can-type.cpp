class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        bitset<26> checkKey; // it use less memory than bool arr[26];
        int res{}; // short form of res = 0

        for(const int& c : brokenLetters){ 
            checkKey[c-97] = true;// mark broken key
        }

        bool okWord = true;

        for(const int& c : text){
            if(c == 32){ // check word when space comes
                if(okWord)   ++res;
                else         okWord = true;
            }

            if(okWord && checkKey[c-97])
                okWord = false;
        }
        return res + okWord;
    }
};