def comp(a, b):
    if len(a) > len(b):
        return -comp(b, a)
    for i in range(len(a)):
        if a[i] < b[i]:
            return -1
        elif a[i] > b[i]:
            return 1
    if len(b) == len(a): return 0
    p, q = int(a+b), int(b+a)
    if p < q:
        return -1
    elif p > q:
        return 1
    else:
        return 0
        
class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        snum = [str(num[i]) for i in range(len(num))]
        snum.sort(comp)
        print snum
        snum.reverse()
        return ''.join(snum)

if __name__ == "__main__":
    s = Solution()
    ret = s.largestNumber([2, 10])
    print ret
