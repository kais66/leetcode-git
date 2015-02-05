class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        
        string last = "1";
        string cur = "";
        for (int i=2; i<=n; ++i) {
            char lastc = '0';
            int size = last.size();
            int num = 0;
            for (int j=0; j<size; ++j) {
                if (last[j] != lastc) {
                    if (j > 0) { cur += (to_string(num) + to_string(lastc - '0')); }
                    lastc = last[j];
                    num = 1;
                } else { ++num; }
            }
            if (num > 0) { cur += (to_string(num) + to_string(lastc - '0')); }
            last = cur;
            cur = "";
        }
        return last;
    }
};
