class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> sk;
        int n = tokens.size();                
        for (int i=0; i<n; ++i) {
            string s = tokens[i];
            if (isOperator(s)) {
                int b = sk.top();
                sk.pop();
                int a = sk.top();
                sk.pop();
                sk.push(calc(a, b, s));
            } else {
                sk.push(toInt(s));
            }
        }
        return sk.top();
    }

    bool isOperator(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") 
            return true;
        else return false;
    }

    int toInt(string s) {
        int ret = INT_MIN;
        stringstream stm(s);
        stm >> ret;
        return ret; 
    }

    int calc(int a, int b, string s) {
        char c = s[0];
        int ret = INT_MIN;
        switch (c) {
            case '+':
                ret = a + b;
                break;
            case '-':
                ret = a - b;
                break;
            case '*':
                ret = a * b;
                break;
            case '/':
                ret = a / b;
                break;
            default:
                break;
        }
        return ret;
    }
};
