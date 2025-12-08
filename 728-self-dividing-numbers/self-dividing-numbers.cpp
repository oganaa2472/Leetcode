class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        while(left<=right){
            if(left>=1&&left<=9){
                result.push_back(left);
            }else{
                bool isCheck = false;
                int l = left;
                int le = left;
                
                while(l>0){
                    int m = l%10;
                    if(m==0) isCheck = true;
                    else if(m!=0&&le%m!=0){
                        isCheck = true;
                    }
                    l = l/10;
                }
                if(isCheck==false)result.push_back(left);
            }
            left++;
        }
        return result;
    }
};