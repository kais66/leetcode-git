class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        vector<vector<int> > ret;
        if (n < 3) return ret;
        sort(num.begin(), num.end());
        for (int i=0; i<n-2; ++i) {
            if (i > 0 && num[i] == num[i-1]) continue;
            int j = i + 1;
            int p = n - 1;
            while (j < p) {
                if (j > i+1 && num[j] == num[j-1]) {
                    ++j; // don't forget this before 'continue'
                    continue;
                }
                if (p < n-1 && num[p] == num[p+1]) {
                    --p;
                    continue;
                }
                int sum = num[i] + num[j] + num[p];
                if (sum == 0) {
                    vector<int> v(3);
                    v[0] = num[i];
                    v[1] = num[j];
                    v[2] = num[p];
                    ret.push_back(v);
                    ++j;
                    --p;
                } else if (sum > 0) { --p; }
                else { ++j; } 
            }
        }
        return ret;
    }
};
