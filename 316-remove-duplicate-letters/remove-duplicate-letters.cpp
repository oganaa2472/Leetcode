class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> seen(26,false);
        unordered_map<char,int> freq;
        for(int ch:s) freq[ch]++;
        stack<char> stack;
        for(char ch:s){
            if(seen[ch-'a']){
                 freq[ch]--;
                 continue;
            }
            
            while(!stack.empty()&&freq[stack.top()]>0&&stack.top()>ch){      
                seen[stack.top()-'a'] = false;
                stack.pop();
               
            }
          stack.push(ch);
          seen[ch-'a'] = true;
          freq[ch]--;
        }
        string answer = "";
        while(!stack.empty()){
            answer.push_back(stack.top());
            stack.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};