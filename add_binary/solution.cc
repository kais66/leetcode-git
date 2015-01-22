class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int rlen = max(m, n) + 1;
        string ret(rlen, '0');
        int i = 0;
        int carry = 0;
        while (i < m || i < n) {
            int ad = (i >= m ? 0 : a[m-1-i] - '0');
            int bd = (i >= n ? 0 : b[n-1-i] - '0'); // b's digit
            int sum = ad + bd + carry;
            ret[rlen-1-i] = sum % 2 + '0';
            carry = sum / 2;
            ++i;
        }
        if (carry == 1) {
            ret[rlen-1-i] = '1';
            i++;
        }
        return ret.substr(rlen-i, -1); // get substring from indicated position to end
    }
};
