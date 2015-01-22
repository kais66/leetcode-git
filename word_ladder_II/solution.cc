class Solution {
public:
    // http://blog.csdn.net/whuwangyi/article/details/21611433
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ret;
        if (start.empty()) return ret;              
        dict.insert(end);
        queue<string> wq; // word queue 
        queue<int> lq; // length queue
        wq.push(start);
        lq.push(1);

        unordered_map<string, vector<string> > pre; // precedent; also used to track discovered nodes
        int size = start.size();
        int minLen = INT_MAX;
        
        while (!wq.empty()) {
            string s = wq.front();
            int len = lq.front();
            wq.pop();
            lq.pop();
            if (len > minLen) break;

            for (int i=0; i<size; ++i) {
                string nb = s;
                for (char c='a'; c<='z'; ++c) {
                    nb[i] = c;
                    if (dict.find(nb) != dict.end(){ 
                        if (pre.find(nb) == pre.end()) {
                            if (nb == end && minLen > len + 1) { minLen = len + 1; }
                            pre.insert(pair<string, vector<string>(nb, vector<string>()));
                            pre[nb].push_back(s); 
                            
                            wq.push(nb);
                            lq.push(len + 1);
                        } else {
                            pre[nb].push_back(s);
                        }
                    }
                }
            }
        }

        // then use DFS to generate all paths
        vector<string> path(1, end);
        solveRec(ret, path, start, minLen, pre);
        return ret;
    }

    void solveRec(vector<vector<string> > &ret, vector<string> &path, string &start, int len, unordered_map<string, vector<string> > &pre) {
        int n = path.size();
        if (n == len) {
            if (path[n-1] == start) {
                vector<string> v = path;
                reverse(v.begin(), v.end());
                ret.push_back(v);
            }
            return;
        }
        
        vector<string> &vref = pre[path[n-1]];
        int numPre = vref.size();
        for (int i=0; i<numPre; ++i) {
            path.push_back(vref[i]);
            solveRec(ret, path, start, len, pre);
            path.pop_back();
        }
    }
};
