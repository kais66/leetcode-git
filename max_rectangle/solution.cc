class Solution {
public:
    struct Rec {
        int width;
        int height;
        Rec (int a, int b) : width(a), height(b) {};
    };

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        if (matrix[0].empty()) return 0;
        int height = matrix.size();
        int width = matrix[0].size();

        vector<vector<Rec> > area(height, vector<Rec>(width, Rec(0,0))); // area (width, height) of rectangle with (x, y) has the bottom right point
        if (matrix[0][0] == '1') {
            setRec(area[0][0], 1, 1);
        } else {
            setRec(area[0][0], 0, 0);
        }

        for (int i=1; i<width; ++i) {
            if (matrix[0][i] == '1') setRec(area[0][i], 1, 1+area[0][i-1].width);
            else setRec(area[0][i], 0, 0);
        }
        for (int i=1; i<height; ++i) {
            if (matrix[i][0] == '1') setRec(area[i][0], 1, 1+area[i-1][0].width);
            else setRec(area[i][0], 0, 0);
        }

        int maxa = 0;
        for (int i=1; i<height; ++i) {
            for (int j=1; j<width; ++j) {
                if (matrix[i][j] == '0') { setRec(area[i][j], 0, 0); }
                else {
                    if (!area[i-1][j-1].height) {
                        int len = max(area[i-1][j]. 
                         || !area[i-1][j-1].height || area[i-1][j-1].height) {
                        setRec(area[i][j], 1, 1); 
                    } else {
                        int h = min(area[i-1][j-1].height+1, area[i-1][j].height+1, area[i][j-1].height);
                        int w = min(area[i-1][j-1].width+1, area[i-1][j].width, area[i][j-1].width+1);
                        if (!h || !w) { setRec(area[i][j], 1, 1); }
                        else { setRec(area[i][j], h, w); }
                }
            }
        }
        for (int i=0; i<height; ++i) {
            for (int j=0; j<width; ++j) {
                int a = area[i][j].width * area[i][j].height;
                if (a > maxa) maxa = a;
            }
        }
        return maxa;
    }

    void setRec(Rec &r, int a, int b) {
        r.height = a;
        r.width = b;
    }
};
