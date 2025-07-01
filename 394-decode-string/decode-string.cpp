class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;

        for (char& c : s) {
            if (c != ']') {
                stack.push_back(string(1, c));
            } else {
                string substr = "";
                while (stack.back() != "[") {
                    substr = stack.back() + substr;
                    stack.pop_back();
                }
                stack.pop_back();

                string k = "";
                while (!stack.empty() && isdigit(stack.back()[0])) {
                    k = stack.back() + k;
                    stack.pop_back();
                }
                int repeatCount = stoi(k);

                string repeated = "";
                for (int i = 0; i < repeatCount; ++i) {
                    repeated += substr;
                }
                stack.push_back(repeated);
            }
        }

        string res = "";
        for (const string& part : stack) {
            res += part;
        }

        return res;
    }
};