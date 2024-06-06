class Solution(object):
    def scoreOfString(self, s):
        """
        :type s: str
        :rtype: int
        """
        #score = 0
        #for char in range(len(s)-1):
        #    score += abs(ord(s[char+1])-ord(s[char]))
        #return score
        
        return sum(abs(ord(s[char + 1])-ord(s[char])) for char in range(len(s)-1))