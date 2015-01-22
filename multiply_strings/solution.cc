class Solution {
public:
    // basic multiplication process: ret saves current prod, carry saves 
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if (num1[0] == '0' || num2[0] == '0') return "0"; // because this is a corner case: 5411*0 = 0, only single digit
        string ret(n1+n2, '0'); // result should be either (n1+n2) bits or (n1+n2-1) bits.
        for (int i=n1-1; i >=0; --i) {
            int carry = 0;
            for (int j=n2-1; j >= 0; --j) {
                int prod = toInt(num1[i]) * toInt(num2[j]) + toInt(ret[i+j+1]) + carry; 
                // this processing only determines bit(i+j+1)
                ret[i+j+1] = prod % 10 + '0';
                carry = prod / 10;
            }
            if (carry > 0) ret[i] = carry + '0'; // ** the inner loop only writes num2 digits, need to deal with carry
        }
        return (ret[0] == '0' ? ret.substr(1) : ret);
    }

    int toInt(char c) {
        return c - '0';
    }
};
