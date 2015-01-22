class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;
        int max = 0;

        height.push_back(0);
        stack<int> sk; // stack of indices

        int i = 0;
        // loop invariant: stack has a sequence of indices, which are related to a increasing height sequence for which
        // all possible combinations of areas haven't be considered yet.
        while (i < n+1) { // note length is now n+1
            if (sk.empty() || height[i] >= height[sk.top()]) {
                sk.push(i);
                i++;
            } else {
                int top = sk.top();
                sk.pop();
                int area = 0; // area
                area = height[top] * (sk.empty() ? i : i-1-sk.top());
                if (max < area) max = area;
            }
        }
        height.pop_back();
        return max;
    }
};
