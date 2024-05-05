class Solution(object):
    def reversePrefix(self, word, ch):
        """
        :type word: str
        :type ch: str
        :rtype: str
        """
        
        idx =  word.find(ch)
        if idx == -1:
            return word

        start = 0
        end = idx

        word = word[:start] + word[start:end + 1][::-1] + word[end + 1:]
        return word
