class Solution {
public:
    // this one is easier to code: the if conditions are simplified.
    // no need to optimize, constructing a vector alone takes O(n) time
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (newInterval.start > newInterval.end) return intervals;
        vector<Interval> ret;                
        ret.push_back(newInterval); 
        int n = intervals.size();
        // loop invariant: all intv before cur are fixed (no need to merge, etc..)
        for (int i=0; i<n; ++i) {
            Interval &cur = ret[ret.size()-1];
            Interval &inp = intervals[i];
            if (inp.start > cur.end) { ret.push_back(inp); }
            else if (inp.end < cur.start) { ret.insert(ret.end()-1, inp); } // constant time operation, because only need to more 2 interval objects
            else {
                cur.start = min(inp.start, cur.start);
                cur.end = max(inp.end, cur.end);
            }
        }
        return ret;
    } 
};
