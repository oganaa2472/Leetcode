class Solution {
public:
    bool isValid(string word){
        int cnt = 0;
        string str = "";
        for(char ch:word){
            
            if(isalpha(ch)){
            }else if(isdigit(ch)||ch=='_'){
            }
            else return false;
        }
        
        return true;
    }
    bool isWord(string s){
        if(s=="electronics"||s=="grocery"||s=="restaurant"||s=="pharmacy"){
            return true;
        }
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string,string>> answer;
        for(int i = 0;i<n;i++){
            if(isActive[i]&&code[i].size()>0&&isValid(code[i])&&isWord(businessLine[i])){
                answer.push_back({businessLine[i],code[i]});
            }
        }
        sort(answer.begin(),answer.end());
        vector<string> result(answer.size());
        for(int i = 0;i<answer.size();i++){
            result[i] = answer[i].second;
        }
        return result;
    }
};