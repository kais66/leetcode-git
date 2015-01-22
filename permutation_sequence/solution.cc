class Solution {
public:
    // algo: for n digits, for k, look at k/(n-1)!...
    string getPermutation(int n, int k) {
        if (n <= 0) {
            string ret;
            return ret;
        }
        string ret(n, '.'); 

        int rem = k - 1;
        int i = n-1;
        int val = fact(i);
        vector<bool> avail(n, true);
        while (i >= 0) {
            int digit = rem / val;

            int seq = 0;
            for (int j=0; j<n; ++j) {
                if (!avail[j]) continue;
                if (seq == digit) {
                    ret[n-1-i] = (j + 1) + '0';
                    avail[j] = false;
                    break;
                } else { seq++; }
            }

            rem = rem % val;
            if (i == 0) break;
            val /= i;
            i--;
        }
        return ret;
    }

    int fact(int n) {
        int ret = 1;
        for (int i=1; i<=n; ++i) {
            ret *= i;
        }
        return ret;
    }

};
