class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        self.comb = []
        candidates.sort()
        self.solveRec(candidates, target, 0, [])
        return self.comb
        
    def solveRec(self, num, rem, ind, base):
        if rem <= 0:
            if rem == 0: self.comb.append(base[:])
            print 'rem is: ' + str(rem)
            print base
            print self.comb
            return
        for i in range(ind, len(num)):
            base.append(num[i])
            self.solveRec(num, rem-num[i], i, base)
            print self.comb
            base.pop()
            print self.comb
        
s = Solution()
print s.combinationSum([1], 1)
