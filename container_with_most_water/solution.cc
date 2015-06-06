class Solution {
public:
    // When we move the pointer, the width of the area decrease. If the height is smaller than the previous height, then it’s impossible that the area will increase. In other words, if left is shorter than right, no matter how you move your right pointer, you can’t find a area larger than it.
    int maxArea(vector<int> &height) {
        int n = height.size();
        int p = 0;
        int q = n - 1;
        int maxa = 0;
        while (p < q) {
            int area = min(height[p], height[q]) * (q-p);
            maxa = max(maxa, area);
            if (height[p] >= height[q]) { --q; }
            else { ++p; }
        }
        return maxa;
    }
};
