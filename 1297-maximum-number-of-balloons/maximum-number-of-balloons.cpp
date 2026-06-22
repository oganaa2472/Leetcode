class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(int i =0;i<text.size();i++){
            mp[text[i]]++;
        }
        if(mp['o']==0){
            return 0;
        }
        if(mp['l']==0){
            return 0;
        }
        mp['o']=mp['o']/2;
        mp['l']=mp['l']/2;
        int answer = min(mp['o'],min(mp['l'],min(mp['b'],min(mp['a'],mp['n']))));
        return answer;
    }
};