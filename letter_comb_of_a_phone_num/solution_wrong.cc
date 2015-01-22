class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> dic(10);
        initDic(dic);
        // this is wrong, string doesn't have corresponding ctor. must specify the char
        string base(digits.size());
        solveRec(ret, base, digits, 0, dic);
        return ret;    
    }

    void solveRec(vector<string> &ret, string &base, string &digits, int ind, vector<string> &dic) {
        if (ind == digits.size()) {
            ret.push_back(base);
            return;
        }
        int d = digits[ind] - '0';
        string s = dic[d];
        int n = s.size();
        for (int i=0; i<n; ++i) {
            base[ind] = s[i];
            solveRec(ret, base, digits, ind+1, dic);
        }
    }

    void initDic(vector<string> &dic) {
        dic[2] = "abc";
        dic[3] = "def";
        dic[4] = "ghi";
        dic[5] = "jkl";
        dic[6] = "mno";
        dic[7] = "pqrs";
        dic[8] = "tuv";
        dic[9] = "wxyz";
    }
};
