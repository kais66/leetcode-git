class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > ret;
        if (n < 4) return ret;

        for (int i=0; i<n-3; ++i) {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (int j=i+1; j<n-2; ++j) {
                if (j > i+1 && num[j] == num[j-1]) continue;
                int a = j + 1;
                int b = n - 1;
                while (a < b) {
                    if (a > j+1 && num[a] == num[a-1]) {
                        ++a;
                        continue;
                    } 
                    if (b < n-1 && num[b] == num[b+1]) {
                        --b;
                        continue;
                    }
                    int sum = num[i] + num[j] + num[a] + num[b];
                    if (sum > target) { --b; }
                    else if (sum < target) { ++a; }
                    else { // equal
                        vector<int> v = {num[i], num[j], num[a], num[b]};
                        ret.push_back(v);
                        ++a;
                        --b;
                    }
                }
            }
        }
        return ret;
    }
};
