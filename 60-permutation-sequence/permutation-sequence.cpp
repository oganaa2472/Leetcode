class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> mynumber; 
        int fact = 1;
        for(int i=1; i<n; i++){
            fact = fact * i;
            mynumber.push_back(i);
        }
        mynumber.push_back(n);
        string res = "";
        k--;
        while(1){
            int currentIndex = k/(fact);
            res = res + to_string(mynumber[currentIndex]);
            k = k % fact;
            mynumber.erase(mynumber.begin()+currentIndex);
            if(mynumber.size()==0) break;
            fact = fact/mynumber.size();
        }
        return res;
    }
};