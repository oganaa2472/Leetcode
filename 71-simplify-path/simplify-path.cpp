class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string cur;
        stringstream ss(path);
        while (getline(ss, cur, '/')) {
            if (cur.empty()) continue;
            if (cur == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (!cur.empty() && cur != ".") {
                stack.push_back(cur);
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            if (i > 0) result += "/";
            result += stack[i];
        }

        return result;

    }
};