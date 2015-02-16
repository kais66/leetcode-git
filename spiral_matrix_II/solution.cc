class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > em;
        if (n <= 0) return em;
        vector<vector<int> > ret(n, vector<int>(n, 0));
        int sq = n * n;                
        int layers = (n%2 == 1 ? n/2+1 : n/2);
        int num = 1;
        for (int i=0; i<layers; ++i) {
            int r = n-1-i;
            int d = n-1-i;
            int l = i;
            int u = i+1;
            for (int j=i; j<=r; ++j) {
                ret[i][j] = num++;
                if (num > sq) return ret;
            }
            for (int j=i+1; j<=d; ++j) {
                ret[j][r] = num++;
                if (num > sq) return ret;
            }
            for (int j=r-1; j>=l; --j) {
                ret[d][j] = num++;
                if (num > sq) return ret;
            }
            for (int j=d-1; j>=u; --j) {
                ret[j][l] = num++;
                if (num > sq) return ret;
            }
        }
        return ret;
    }
};
