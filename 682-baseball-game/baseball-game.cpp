class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stack;
        int res = 0;
        for (const string& op : ops) {
            if (op == "+") {
                int top = stack.top(); stack.pop();
                int newTop = top + stack.top();
                stack.push(top);
                stack.push(newTop);
                res += newTop;
            } else if (op == "D") {
                stack.push(2 * stack.top());
                res += stack.top();
            } else if (op == "C") {
                res -= stack.top();
                stack.pop();
            } else {
                stack.push(stoi(op));
                res += stack.top();
            }
        }
        return res;
    }
};