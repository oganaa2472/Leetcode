class Solution {
public:
    string convert(string s, int numRows) {
        int size =s.size();
        if(numRows==1)
            return s;
        

        if(numRows>=size) 
            return s;
        int direction = -1;

        int row = 0;
        vector<string> res(numRows,"");

        for(int i = 0;i<s.size();i++){

            if(row==0||row==numRows-1){
                direction *=-1;
            }
            res[row]+=s[i];
            row=row+direction;
        }
        string ans;

        for(auto &it : res) ans += it; 

        return ans;
    }
};