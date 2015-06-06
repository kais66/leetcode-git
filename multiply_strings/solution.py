class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
        if not num1 or not num2 or num1[0] == '0' or num2[0] == '0':
            return '0'
        l1, l2 = len(num1), len(num2)
        ret = ['0' for i in range(l1 + l2)] # when no operand is 0, prod should be of length l1+l2 or l1+l2-1
        for i in range(l1-1, -1, -1):
            carry = 0
            for j in range(l2-1, -1, -1):
                prod = int(num2[j]) * int(num1[i]) + carry + int(ret[i+j+1])
                print 'before computing: %d, %d, %d, %d' % (int(num2[j]), int(num1[i]), carry, int(ret[i+j+1]),)
                print 'prod is: ' + str(prod)

                carry = prod // 10
                ret[i+j+1] = str(prod % 10)
                print 'after compting'
                print 'carry is: ' + str(carry)
                print 'ret[i+j+1] is: ' + ret[i+j+1]
            ret[j] = str(carry)
        ret = ''.join(ret)
        if ret[0] == '0': return ret[1:]
        else: return ret

s = Solution()
print s.multiply('98', '9')
