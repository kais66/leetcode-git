class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int i = n - 1;
        while (i >=0 && s[i] == ' ') { --i; }

        int end = i;
        while (i >= 0 && s[i] != ' ') { --i; }
        return end - i;
    }
};
