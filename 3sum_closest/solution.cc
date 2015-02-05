class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int ret = num[0] + num[1] + num[2];
        int n = num.size();
        for (int i=0; i<n-2; ++i) {
            int j = i + 1;
            int p = n - 1;
            while (j < p) {
                int sum = num[i] + num[j] + num[p];
                if (abs(target - ret) > abs(target - sum)) { ret = sum; } 

                if (sum > target) { --p; }
                else if (sum < target) { ++j; }
                else { return target; }
            }
        }
        return ret;
    }
};
