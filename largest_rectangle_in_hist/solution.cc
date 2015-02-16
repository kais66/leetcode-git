class Solution {
public:
    // key observation: Stack top stores an index of which the possible rectangle hasn't been evaluated; note that the largest rectangle will end right before an index further right belongs to a less height than the top of stack. Only when we hit that index, we start evaluating.
    // algo: maintain a stack. Iterate over the array, push index to stack if heigh is no less than the top; otherwise, we evaluate every element in stack which has a height that's larger than the current one.
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
                area = height[top] * (sk.empty() ? i : i-1-sk.top()); // height[top] is the index that is currently evaluated, its right is i, and its left is the index further down the stack, or -1 if stack is empty (itself is the only element in stack) 
                if (max < area) max = area;
            }
        }
        height.pop_back();
        return max;
    }
};
