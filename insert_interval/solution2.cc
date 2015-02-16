class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (newInterval.start > newInterval.end) return intervals;
        vector<Interval> ret;                
        ret.push_back(newInterval); 
        int n = intervals.size();
        // loop invariant: all intv before cur are fixed (no need to merge, etc..)
        for (int i=0; i<n; ++i) {
            Interval &cur = ret[ret.size()-1];
            Interval &inp = intervals[i];
            if (inp.start > cur.start) {
                if (inp.start > cur.end) { ret.push_back(inp); }
                else { cur.end = max(cur.end, inp.end); }
            } else { // inp.start <= cur.start
                if (cur.start > inp.end) { ret.insert(ret.end()-1, inp); }
                else { 
                    cur.start = min(inp.start, cur.start);
                    cur.end = max(inp.end, cur.end);
                }
            }
        }
        return ret;
    } 
};
