class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> mymap;

        map<string,int> check;
        int n = s.size();
        int k = words.size();
        int m = 0;
        for(auto& word:words){
            mymap[word]++;
            m=word.size();
        }
        vector<int> answer;
        int end= 0;
        int start=0;
     
        while(end<=n-(k*m)){
            string sub = s.substr(end,m);
            if(mymap.find(sub)!=mymap.end()){
                for(int i = end;i<(k*m)+end;i+=m){
                    check[s.substr(i,m)]++;
                    // cout<<" "<<s.substr(i,m);
                }
                // cout<<"kk"<<" "<<endl;
                if(check==mymap){
                    answer.push_back(end);
                }
                check.clear();
                // end ++;
                // continue;
            }
            end++;
        }
        return answer;

    }
};