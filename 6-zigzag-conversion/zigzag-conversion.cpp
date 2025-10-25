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
        vector<char> res[numRows];

        for(auto c:s){
            res[row].push_back(c);

            if(row==0||row==numRows-1){
                direction *=-1;
            }
            row=row+direction;
        }
        string result = "";
        for(auto x:res){
            for(auto y:x){
                result = result + y;
            }
        }
        return result;
    }
};