class Solution {
public:
    string capitalizeTitle(string title) {
        string result;
        vector<string> words;

        string word;
        for (char c : title) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);

        for (string& word : words) {
            if (word.length() <= 2) {
                for (char& c : word) {
                    c = tolower(c);
                }
            } else {
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.length(); i++) {
                    word[i] = tolower(word[i]);
                }
            }

            result += word + " ";
        }

        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};