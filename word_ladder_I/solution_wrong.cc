class Solution {
public:
    // wrong: because there are 26 letters...
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.empty()) return 0;
        int len = INT_MAX;                
        queue<string> wq; // word queue
        queue<int> lq; // length of transformation
        wq.push(start);
        lq.push(1);
        unordered_set<string> unv = dict; // set of unvisited elements
        unv.insert(end);
        if (unv.find(start) != unv.end()) unv.erase(start);
        while (!wq.empty()) {
            string s = wq.front();
            wq.pop();
            int len = lq.front();
            lq.pop();

            int size = s.size();
            for (int i=0; i<size; ++i) {
                string nb = s;
                for (int j=0; j<24; ++j) {
                    nb[i] = 'a' + j;
                    if (unv.find(nb) != unv.end()) {
                        if (nb == end) return len + 1;
                        wq.push(nb);
                        lq.push(len + 1);
                        unv.erase(nb);
                    }
                }
            }
        }
        return 0;
    }
};
