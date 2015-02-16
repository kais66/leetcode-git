class Solution {
public:
    // algo: iterate over the array. For each element, if it's a left, push; if it's a right, peek if stack top is a corresponding
    // left.
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
