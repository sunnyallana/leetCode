class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = copy.deepcopy(heights)
        expected.sort()

        numMismatch = 0

        for i in range(len(heights)):
            if heights[i] != expected[i]:
                numMismatch += 1
        return numMismatch 