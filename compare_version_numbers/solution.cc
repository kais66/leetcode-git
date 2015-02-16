class Solution {
public:
    int compareVersion(string version1, string version2) {
        return compareRec(version1, 0, version2, 0);                
    }

    // 1.2 2.2, 1.2 1.2.3, corner case: 1.0 vs 1, should be equal
    int compareRec(string &v1, int s1, string &v2, int s2) { //s1: start index
        int l1 = getVlen(v1, s1);
        int l2 = getVlen(v2, s2);

        if (l1 == 0 && l2 == 0) return 0;
        int w1 = (l1 > 0 ? stoi(v1.substr(s1, l1)) : 0);
        int w2 = (l2 > 0 ? stoi(v2.substr(s2, l2)) : 0); 
        if (w2 > w1) { return -1; }
        else if (w2 < w1) { return 1; }
        else { return compareRec(v1, s1+l1+1, v2, s2+l2+1); } 

    }

    int getVlen(string &v, int start) {
        int i = start;
        while (i < v.size() && v[i] != '.') { ++i; }
        return i-start;
    }
};
