class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> schar;
        for(int i = 0;i<operations.size();i++){
            if(operations[i]=="C"){
                schar.pop();
            }else if(operations[i]=="D"){
                string t = schar.top();
                int value = stoi(t);
                value*=2;
                schar.push(to_string(value));
            }else if (operations[i]=="+"){  
                string a = schar.top();
                schar.pop();
                string b = schar.top();
                schar.push(a);
                int value = stoi(a)+stoi(b);
                schar.push(to_string(value));
            }else{
                schar.push(operations[i]);
            }
        
        }
        int answer = 0;
        while(!schar.empty()){
            answer += stoi(schar.top());
            schar.pop();
        }
        return answer;
    }
};