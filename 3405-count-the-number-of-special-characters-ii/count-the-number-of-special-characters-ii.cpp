class Solution {
public:
    int numberOfSpecialChars(string word) {
         unordered_map<char, vector<int>> lowerIndices, upperIndices;

    // Step 1: Record indices of lowercase and uppercase appearances
    for (int i = 0; i < word.size(); ++i) {
        if (islower(word[i])) {
            lowerIndices[word[i]].push_back(i);
        } else if (isupper(word[i])) {
            upperIndices[tolower(word[i])].push_back(i); // Map uppercase to lowercase
        }
    }

    // Step 2: Check for special letters
    int specialCount = 0;
    for (const auto& pair : lowerIndices) {
        char c = pair.first;
        if (upperIndices.find(c) != upperIndices.end()) { // Must appear in both lower and upper
            // Get the last lowercase index and the first uppercase index
            int lastLowerIndex = *max_element(lowerIndices[c].begin(), lowerIndices[c].end());
            int firstUpperIndex = *min_element(upperIndices[c].begin(), upperIndices[c].end());

            // Check if all lowercase indices are before the first uppercase index
            if (lastLowerIndex < firstUpperIndex) {
                ++specialCount;
            }
        }
    }

    return specialCount;
    }
};