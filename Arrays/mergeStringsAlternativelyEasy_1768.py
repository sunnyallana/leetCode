class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        result = ""
        lengthForLoop = min(len(word1), len(word2))
        
        for i in range(lengthForLoop):
            result += (word1[i] + word2[i])

    
        return result + word1[lengthForLoop:] + word2[lengthForLoop:]