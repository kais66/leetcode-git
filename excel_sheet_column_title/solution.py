class Solution:
    # @return a string
    def convertToTitle(self, num):
        if num <= 0: return ''
        num -= 1
        power = 1
        rm = 0
        while rm < 0x7fffffff//26 and rm * 26 + 26 <= num:
            power *= 26
            rm = rm * 26 + 26 
        num -= rm # key:
        print "num is: %d, rm: %d" % (num, rm)        
        ret = ''
        while power > 0:
            ret += chr((num // power) + ord('A'))
            print ret
            num = num % power
            power //= 26
        return ret

if __name__ == "__main__":
    s = Solution()
    print s.convertToTitle(701)
