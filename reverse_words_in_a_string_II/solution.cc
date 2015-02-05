class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        reverse(s, 0, n-1);

        // two pointers, each points to a space, the char in-between are letters
        int end = 0;
        // end points to a non-space char
        while (end < n) {
            int start = end;
            while (end < n && s[end] != ' ') { ++end; } // skipping chars
            reverse(s, start, end-1);
            ++end;
        }
    }

    void reverse(string &s, int i, int j) {
        int n = s.size();
        for (; i<=j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};
