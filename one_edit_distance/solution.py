class Solution:
    # @param s, a string
    # @param t, a string
    # @return a boolean
    # assuming we can only know hasNext(), getCur(), i.e. iterator interface, how to solve this question?
    def isOneEditDistance(self, s, t):
        self.init(s, t)
        
        diff = 0
        singleRep, singleIns, singleRm = True, True, True
        prevS, prevT = None, None
        while (singleRep or singleIns or singleRm) and (self.sHasNext() and self.tHasNext()):
            curS, curT = self.sNext(), self.tNext()
            if diff == 1:
                if curS != curT: singleRep = False
                if curS != prevT: singleIns = False
                if curT != prevS: singleRm = False
            elif curS != curT:
                diff += 1
            
            if diff == 1: prevS, prevT = curS, curT
            
        if not self.sHasNext() and not self.tHasNext(): # same length
            singleRm, singleIns = False, False
            
        while self.sHasNext():
            singleRep, singleRm = False, False
            curS = self.sNext()
            if not prevS: diff += 1
            elif curS != prevT:
                singleIns = False
        
        while self.tHasNext():
            singleRep, singleIns = False, False
            curT = self.tNext()
            if not prevT: diff += 1
            elif curT != prevS:
                singleRm = False
        #return (singleRep or singleRm or singleIns) and diff <= 1
        return (singleRep or singleRm or singleIns) and diff == 1
                
    def init(self, s, t):
        self.s, self.t = s, t
        self.slen, self.tlen = len(s), len(t)
        self.sPos, self.tPos = 0, 0
        
    def sHasNext(self):
        return self.sPos < self.slen
        
    def tHasNext(self):
        return self.tPos < self.tlen
        
    def sNext(self):
        self.sPos += 1
        return self.s[self.sPos-1]
    def tNext(self):
        self.tPos += 1
        return self.t[self.tPos-1]
    