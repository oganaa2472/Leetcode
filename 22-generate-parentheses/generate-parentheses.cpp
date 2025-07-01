class Solution {
public:
    void back(int start,int end,int n,vector<string>& res,string& sta){
        if(start==end && start == n){
            res.push_back(sta);
            return;
        }

        if(start<n){
            sta+='(';
            back(start+1,end,n,res,sta);
            sta.pop_back();
        }
        if(end<start){
            sta+=')';
            back(start,end+1,n,res,sta);
            sta.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        back(0,0,n,res,stack);
        return res;
    }
};