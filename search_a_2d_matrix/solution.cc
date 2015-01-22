class Solution {
public:
    // algo: search first column to locate a row; then search that row.
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int r = matrix.size();
        int c = matrix[0].size();
        
        int start = -1;
        int end = r;
        // a[start] <= target < a[end]
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (matrix[mid][0] <= target) { start = mid; }
            else { end = mid; }
        }
        if (start == -1) return false;

        int row = start;
        start = -1;
        end = c;
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (matrix[row][mid] <= target) { start = mid; }
            else { end = mid; }
        }
        if (matrix[row][start] != target) { return false; }
        else { return true; }
    }
};

