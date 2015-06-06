class Solution:
    # @return an integer
    def romanToInt(self, s):
        dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        ret = 0
        size = len(s)
        for i in range(size):
            if i < size - 1 and dic[s[i]] < dic[s[i+1]]:
                ret -= dic[s[i]]
            else: 
                ret += dic[s[i]]
        return ret

