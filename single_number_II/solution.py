import sys

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        cnt = [0 for i in range(32)]
        for x in A:
            for i in range(32):
                if (1 << i) & x != 0: cnt[i] += 1
        ret = 0
        for i in range(32):
            print '%d th bit, value is: %d\n' % (i, cnt[i])
            #if cnt[i] % 3 != 0: ret |= (1 << i)
            if cnt[i] % 3 != 0: ret |= ((1 << i) & 0xffffffff)
        if ret > 0x7fffffff:
            print 'max: %d, ret: %d' % (0x7fffffff, ret)
            ret = ~ret + 1
            ret &= 0xffffffff
            print ret
        return ret
        
if __name__ == '__main__':
    s = Solution()
    arr =   [-2,-2,1,1,-3,1,-3,-3,-4,-2]
    s.singleNumber(arr) 
