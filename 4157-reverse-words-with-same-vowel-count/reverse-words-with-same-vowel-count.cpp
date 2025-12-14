class Solution {
private:
        int check(string s){
            int count =0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                    count++;
                }
            }
            return count;
        }
public:
    string reverseWords(string s) {

        string ans;
        string local = "";
        int z = -1; 

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!local.empty()) {
                    int o = check(local);
                    if (z == -1) {
                        z = o; 
                        ans += local + " ";
                    } else {
                        if (o == z) {
                            reverse(local.begin(), local.end());
                        }
                        ans += local + " ";
                    }
                    local.clear();
                }
            } else {
                local.push_back(s[i]);
            }
        }

        
        if (!local.empty()) {
            int y = check(local);
            if (z == -1) {
                z = y;
                ans+=local;
            }else{
                if (y == z) {
                    reverse(local.begin(), local.end());
                }    
                ans += local;
            }
            
            
        }

        return ans;
        
    }
};