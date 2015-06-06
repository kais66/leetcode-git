class Solution:
    dic = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
    lst = []
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if not digits:
            return []
        self.solveRec(digits, 0, '')
        return self.lst
        
    def solveRec(self, digits, ind, base):
        if ind == len(digits):
            self.lst.append(base)
            return 
        s = self.dic[digits[ind]]
        for i in range(len(s)):
            base += s[i]
            self.solveRec(digits, ind+1, base)
            base = base[0:-1]

s = Solution()
print s.letterCombinations("3")
