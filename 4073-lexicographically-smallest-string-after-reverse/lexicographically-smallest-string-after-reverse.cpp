class Solution {
public:
    string lexSmallest(string s) {
        string best = s;
        for(int i = 1;i<=s.size();i++){
            string first = s;
            reverse(first.begin(),first.begin()+i);
        
            string last = s;
            reverse(last.end()-i,last.end());
            best = min({last,first,best});
        }
        return best;
    }
};