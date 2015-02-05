class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int start = -1;
        int end = n-1;     

        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (num[end] > num[mid]) {
                end = mid;
            } else if (num[end] < num[mid]) { // num[end] < num[mid]
                start = mid;
            } else {
                --end;
            }
        }
        if (start > -1) { return min(num[start], num[end]); }
        else { return num[end]; }
    }
};
