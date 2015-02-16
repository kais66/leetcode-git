class Solution {
public:
    // WRONG: this is based on matrix[0] laying on the bottom of the matrix
    // http://blog.csdn.net/kenden23/article/details/17200067
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();           
        for (int i=0; i<n/2; ++i) { // m=n/2 layers, initial values of outer loop are (0,0), (1,1)..
            for (int j=i; j<n-1-i; ++j) { // outmost layer has 4n-4 elements
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][n-1-i]; // to figure out the indices, try to do (0,1) in a 4by4 matrix
                matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = temp;
            }
        }
    }
};
