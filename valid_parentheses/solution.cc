class Solution {
public:
    bool isValid(string s) {
        bool ret = true;
        stack<char> sk;
        int n = s.size();
        for (int i=0; i<n; ++i) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                sk.push_back(c);
            } else {
                if (sk.empty()) {
                    ret = false;
                    break;
                }
                char top = sk.top();
                if ((c == ')' && top !='(') 
                    || (c == ']' && top != '[')
                    || (c == '}' && top != '{')) {
                    ret = false;
                    break;
                } else {
                    sk.pop();
                }
            }
        }
        if (!sk.empty()) ret = false;
        return ret;
    }
};
