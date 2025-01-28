class Solution {
public:
    bool isCheck(map<char,long long>& mymap,map<char,long long>& check){
        for(auto&[x,y]:mymap){
            if(check[x]<y) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,long long> mymap;
        if(t.size()>s.size()) return "";

        for(auto& tt:t){
            mymap[tt]++;
        }
        bool found =false;
        long long start = 0;
        long long minanswer = INT_MAX;
        string answer = "";
        map<char,long long> check;
        long long end = 0;
        long long left = 0;
        long long right = s.size()-1;
        long long n = mymap.size();
        
        while(end<s.size()){

            if(mymap.find(s[end])!=mymap.end()){
                mymap[s[end]]--;
                if(mymap[s[end]]==0)
                    n--;
            }
            end++;
            if(n>0) continue;

            
            while(n==0){
                if(mymap.find(s[start])!=mymap.end()){
                    mymap[s[start]]++;
                    if(mymap[s[start]]>0) n++;
                    
                }
                start++;
            }
            if(minanswer>end+1-start){
                left = start;
                right = end;
                found = true;
                minanswer = end+1-start;
            }
            // check[s[end]]++;
            // while(isCheck(mymap,check)&&start<s.size()){
            //     if(minanswer>end+1-start){
            //         minanswer = end+1-start;
            //         answer = s.substr(start,minanswer);
            //     }
            //     check[s[start]]--;
            //     if(check[s[start]]==0) check.erase(s[start]);
            //     start++;
            // }
            // end++;
        }
        return !found?"":s.substr(left-1,minanswer);

    }
};