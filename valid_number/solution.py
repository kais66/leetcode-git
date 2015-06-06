class Solution:
    # @param s, a string
    # @return a boolean
    # 'e', '.'
    # algo: process: +/-, numerical, '.', numerical, 'e', +/-, numerical
    # see how the "hasInt" handles dependencies: 1. either numericals before or right after the '.', a partial number is present and hasInt is set True; 2. to evaluate 'e', there has to be a valid number before 'e'; 3. if a number with a 'e' in it is to be considereed valid, there has to exist numericals after the 'e'.
    def isNumber(self, s):
        l = len(s)
        i = 0
        while i < l and s[i] == ' ': i += 1
        if i == l: return False
        if s[i] == '+' or s[i] == '-': i += 1
        if i == l: return False
        hasInt = False
        while i < l and '0' <= s[i] <= '9': 
            i += 1
            hasInt = True
        if i < l and s[i] == '.':
            i += 1
            while i< l and '0' <= s[i] <= '9':
                i += 1
                hasInt = True
        if hasInt:
            if i < l and s[i] == 'e': 
                i += 1
                hasInt = False
                if i < l and (s[i] == '-' or s[i] == '+'):
                    i += 1
                while i < l and '0' <= s[i] <= '9':
                    i += 1
                    hasInt = True
        while i < l and s[i] == ' ':
            i += 1
        if i < l: return False
        else: return hasInt
