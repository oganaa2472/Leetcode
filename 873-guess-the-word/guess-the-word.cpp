#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;



class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(0));  // Initialize random seed
        for (int i = 0; i < 10; ++i) {  // We are allowed at most 10 guesses
            int idx = rand() % wordlist.size();  // Select a random index
            string guessWord = wordlist[idx];
            int matches = master.guess(guessWord);
            if (matches == 6) return;  // Correct guess

            vector<string> filteredWordlist;
            for (auto& word : wordlist) {
                if (matchCount(word, guessWord) == matches) {
                    filteredWordlist.push_back(word);
                }
            }
            wordlist = filteredWordlist;
        }
    }

private:
    int matchCount(const string& a, const string& b) {
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) count++;
        }
        return count;
    }
};