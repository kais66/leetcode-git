class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return path;

        int last = -1; // index of last slash
        int n = path.size();
       
        stack<string> sk;

        while (last < n-1) {
            int cur = path.find_first_of('/', last + 1);
            if (cur != -1) { // not found
                int len = cur - last - 1;
                if (len > 0) {
                    string sub = path.substr(last + 1, len);
                    if (sub == "..") {
                        if (!sk.empty()) sk.pop();
                    } else if (sub != ".") {
                        sk.push(sub);
                    }
                }
                last = cur;
            } else break;
        } 

        // last sub string
        int len = n - last - 1;
        if (len > 0) {
            string sub = path.substr(last + 1, len);
            if (sub == "..") {
                if (!sk.empty()) sk.pop();
            } else if (sub != ".") {
                sk.push(sub);
            }
        }

        string ret = "";
        while (!sk.empty()) {
            ret = "/" + sk.top() + ret;
            sk.pop();
        }

        return ret.empty() ? "/" : ret;
    }
};
