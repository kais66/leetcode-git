#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    // http://blog.csdn.net/kenden23/article/details/20701069
    void reverseWords(string &s) {
        int n = s.size();
        int start = n - 1;
        string ret = "";
        while (start >= 0 && s[start] == ' ') { --start; }

        while (start >= 0) {
            int end = start;
            while (start >= 0 && s[start] != ' ') { --start; }
            if (!ret.empty()) ret += ' ';
            //if (start+1 > end) { break; }
            ret += s.substr(start+1, end-start);
            while (start >= 0 && s[start] == ' ') { --start; }
        }
        s = ret;
    }
};

int main() {
    string ss = " one. +two three? ~four !five- ";
    Solution s;
    s.reverseWords(ss);
    cout << ss << endl;
    return 0;
}
