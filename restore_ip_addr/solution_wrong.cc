class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if (s.empty()) return ret;                
        
        int n = s.size(); 
        string base = "";
        solveRec(ret, base, 0, 0, s);
        return ret;
    }

    void solveRec(vector<string> &ret, string &base, int ind, int num, string &s) { // num: num of segments
        int n = s.size();
        if (num == 4) {
            if (ind == n) { ret.push_back(base); }
            return;
        }

        if (num < 4) {
            for (int i=1; i<=3; ++i) {
                string news = s.substr(ind, i);
                if (isValid(news)) {
                    if (num == 3) { solveRec(ret, base+news, ind+i, num+1, s); }
                    else { solveRec(ret, base+news+'.', ind+i, num+1, s); }
                }

        }
    }

    bool isValid(string &s) {
        bool valid = false;
        if (s[0] == '0') {
            if (s.size() == 1) { valid = true; }
        } else {
            int itg = stoi(s);
            if (itg > 0 && stg <= 255) { valid = true; } 
        }
        return valid;
    }
};
