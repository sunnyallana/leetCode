class Solution(object):
    def convert(self, s, numRows):

        result = ""

        if numRows <= 1:
            return s
        
        for i in range(numRows):
            increment = (2 * numRows) - 2
            for j in range(i, len(s), increment):
                result += s[j]
                if i > 0 and i < numRows - 1 and j + increment - (2 * i) < len(s):
                    result += s[j + increment - (2 * i)]
                    
        return result