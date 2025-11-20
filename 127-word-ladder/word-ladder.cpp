class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // Convert wordList to a set for O(1) access
        if (wordSet.find(endWord) == wordSet.end()) { // if endWord is not in the dictionary
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int level = 1; // Represents number of transformations
        
        while (!q.empty()) {
            int size = q.size();
            
            // Process all nodes at the current depth level
            for (int i = 0; i < size; i++) {
                string currentWord = q.front();
                q.pop();
                
                // Try changing each letter of the current word to find all possible transformations
                for (int j = 0; j < currentWord.length(); j++) {
                    char originalChar = currentWord[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (currentWord[j] == c) continue; // skip if the character is the same
                        currentWord[j] = c;
                        
                        if (currentWord == endWord) {
                            return level + 1; // Shortest path found
                        }
                        
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord);
                            wordSet.erase(currentWord); // Remove to prevent re-visiting
                        }
                    }
                    currentWord[j] = originalChar; // Restore original letter for next iteration
                }
            }
            level++; // Increment depth level
        }
        
        return 0; // If endWord is not reachable from beginWord
    }
};