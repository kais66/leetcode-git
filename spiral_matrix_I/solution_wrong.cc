class Solution {
public:
    // WRONG: consider the input: [[2, 3]]. Among the 4 for loops, 1st will print all, 2nd won't print, BUT the 3rd will.
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.empty() || matrix[0].empty()) return ret;
        int m = matrix.size();
        int n = matrix[0].size();
        int layers = min(m, n)/2; // gotcha!! need to distinguish two cases
        layers += (min(m, n)%2 == 1 ? 1 : 0);
        for (int i=0; i<layers; ++i) { // layers
            int r = n-1-i; // l,r,u,d are the boundaries
            int d = m-1-i;
            int l = i;
            int u = i + 1;
            // need to make sure j is not visited before
            for (int j=i; j<=r; ++j) ret.push_back(matrix[i][j]);
            for (int j=i+1; j<=d; ++j) ret.push_back(matrix[j][r]);
            for (int j=n-1-i-1; j>=l; --j) ret.push_back(matrix[d][j]);
            for (int j=m-1-i-1; j>=u; --j) ret.push_back(matrix[j][l]);
        }
        return ret;
    }
};
