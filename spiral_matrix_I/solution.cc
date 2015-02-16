class Solution {
public:
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
            int j = i;
            if (j > r) break;
            for (; j<=r; ++j) ret.push_back(matrix[i][j]); 

            j = i + 1;
            if (j > d) break;
            for (; j<=d; ++j) ret.push_back(matrix[j][r]); 

            j = r - 1;
            if (j < l) break;
            for (; j>=l; --j) ret.push_back(matrix[d][j]); 

            j = d - 1;
            if (j < u) break;
            for (; j>=u; --j) ret.push_back(matrix[j][l]); 
        }
        return ret;
    }
};
