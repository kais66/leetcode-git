class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        int i = 0; 
        stack<string> sk;
        while (i < n) {
            while (i<n && path[i] == '/') { ++i; }
            int start = i;
            while (i < n && path[i] != '/') { ++i; }
            if (i > start) {
                string subs = path.substr(start, i-start);
                if (subs == "..") { 
                    if (!sk.empty()) { sk.pop(); }
                } else if (subs != ".") { sk.push(subs); }
            }
        }
        string ret = "";
        while (!sk.empty()) {
            ret = ("/" + sk.top()) + ret;
            sk.pop();
        }
        return (ret == "" ? "/" : ret);
    }
};
