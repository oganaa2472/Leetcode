class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftStack;
        stack<int> starStack;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                leftStack.push(i);
            }else if(s[i]==')'){
                if(!leftStack.empty()){
                    leftStack.pop();
                }else if(!starStack.empty()){
                    starStack.pop();
                }else{
                    return false;
                }
            }else{
                starStack.push(i);
            }
        }
        while(!leftStack.empty()&&!starStack.empty()){
            int leftIndex = leftStack.top();
            int rightIndex = starStack.top();
            leftStack.pop();
            starStack.pop();
            if(rightIndex<leftIndex){
                return false;
            }
        }
        return leftStack.empty();
    }
};