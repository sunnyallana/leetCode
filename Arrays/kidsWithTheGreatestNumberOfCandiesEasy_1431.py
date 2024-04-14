class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """

        currentMaxCandies = max(candies)
        result = []
        for i in range(len(candies)):
            if (candies[i] + extraCandies) >= currentMaxCandies:
                result.append(True)
            else:
                result.append(False)
        return result