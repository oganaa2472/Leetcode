class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> answer;
        answer.push_back(pref[0]);
        int n = pref.size();
        for(int i = 1;i<n;i++){
            answer.push_back(pref[i]^pref[i-1]);
        }
        return answer;
    }
};