class Solution {
public:
    // bottom up really simplifies code here
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        int height = triangle.size();
        vector<int> sm(triangle[height-1]);
        
        for (int i=height-2; i>=0; --i) {
            for (int j=0; j<i+1; ++j) {
                sm[j] = triangle[i][j] + min(sm[j], sm[j+1]);
            }
        }
        return sm[0];
    }
};
