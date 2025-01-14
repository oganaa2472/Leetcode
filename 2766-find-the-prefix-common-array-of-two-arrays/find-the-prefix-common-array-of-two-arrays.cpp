class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> c(A.size());

        unordered_set<int> m;
        int n= B.size();
        for(int i = 0;i<n;i++){
            m.insert(A[i]);
            m.insert(B[i]);
            if(m.size()==i+1){
                c[i] = i+1;
            }else{
                c[i] = (i+1)*2-m.size();
            }
        }
        return c;
    }
};