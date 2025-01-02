class Solution {
public:
        bool check(char ch){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                return true;
            }
            return false;
        }
        vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            if (vowels.count(currentWord[0]) &&
                vowels.count(currentWord[currentWord.size() - 1])) {
                sum++;
            }
            prefixSum[i] = sum;
        }

         for (int i = 0; i < queries.size(); i++) {
           
            int left =  queries[i][0];
            int right =  queries[i][1];
            ans[i] = prefixSum[right] - ((left==0?0:prefixSum[left-1]));
           
        }
        return ans;
    }
};