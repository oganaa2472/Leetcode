class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0;i<n;i++){
            string w1 = words[i];
            for(int j = 0;j<n;j++){
                string w2 = words[j];
                if(i!=j){
                    size_t position = w2.find(w1);

                    if (position != std::string::npos) {
                        ans.push_back(w1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};