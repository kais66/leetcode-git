bool compare(const Interval &i1, const Interval &i2) {
    if (i1.start < i2.start) return true;
    else if (i1.start == i2.start && i1.end < i2.end) return true;
    else return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(), compare);
        ret.push_back(intervals[0]);
        int n = intervals.size();
        for (int i=1; i<n; ++i) {
            Interval &cur = ret[ret.size()-1]; 
            Interval &inp = intervals[i];
            if (cur.end < inp.start) { ret.push_back(inp); }
            else { // merge (it's guaranteed that cur.start <= inp.start <= inp.end)
                cur.start = min(cur.start, inp.start);
                cur.end = max(cur.end, inp.end);
            }
        }
        return ret;        
    }
};
