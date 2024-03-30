class Solution(object):
    """
    This class provides a solution for finding the length of the longest substring
    without repeating characters.
    """

    def lengthOfLongestSubstring(self, s):
        """
        Method to find the length of the longest substring without repeating characters.
        
        :param s: Input string
        :return: Length of the longest substring without repeating characters
        """
        character_set = set()
        left_window = 0
        longest_length = 0
        for right_window in range(len(s)):
            while s[right_window] in character_set:
                character_set.remove(s[left_window])
                left_window += 1
            character_set.add(s[right_window])
            longest_length = max(longest_length, right_window - left_window + 1)
        return longest_length
