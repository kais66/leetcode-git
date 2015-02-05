class Solution {
public:
    // http://blog.csdn.net/linhuanmars/article/details/20342851
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.empty()) return ret;  
        int wn = L[0].size();
        int num = L.size();
        int sn = S.size();
        unordered_map<string, int> lfreq;
        for (auto &s : L) {
            if (lfreq.find(s) == lfreq.end()) { lfreq[s] = 1; }
            else { lfreq[s] += 1; }
        }

        for (int i=0; i<wn; ++i) {
            unordered_map<string, int> sfreq;
            int start = -1;
            int cnt = 0;
            for (int j=i; j<sn; j=j+wn) {
                string cur = S.substr(j, wn);
                if (lfreq.find(cur) != lfreq.end()) { // a word of interest
                    if (start == -1) start = j;

                    if (sfreq.find(cur) != sfreq.end()) { ++sfreq[cur]; }
                    else { sfreq[cur] = 1; }

                    ++cnt;
                    while (sfreq[cur] > lfreq[cur]) {
                        string del = S.substr(start, wn); 
                        if (sfreq.find(del) != sfreq.end()) {
                            --sfreq[del];
                            --cnt;
                        }
                        start += wn;
                    }
                    if (cnt == num) ret.push_back(j-wn*(num-1)); // remember j is the start of last word
                } else { 
                    sfreq.clear();
                    cnt = 0;
                    start = -1;
                }
            }
        }
        return ret;
    }
};
