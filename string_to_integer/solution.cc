class Solution {
public:
    // cleanCode book (leetcode book)
    int atoi(const char *str) {
        int ret = 0;                  
        int i = 0;
        while (str[i] == ' ') i++; // skip white space char
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            ++i;
        } else if (str[i] == '+') { ++i; }

        while (str[i] != '\0' && isDigit(str[i])) {
            int d = toInt(str[i]);
            if (ret > INT_MAX/10 || (ret == INT_MAX/10 && d >= INT_MAX % 10 + 1)) { // learn how to deal with overflow
                return (sign == -1 ? INT_MIN : INT_MAX);
            }
            ret = ret * 10 + d;
            i++;
        }
        return sign * ret;
    }

    bool isDigit(char c) {
        if (c >= '0' && c <= '9') return true;
        else return false;
    }
    int toInt(char c) {
        return c - '0';
    }
};
