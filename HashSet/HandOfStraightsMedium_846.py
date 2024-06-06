class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        
        # Conditions to satisfy to ensure each division is of groupSize
        if ((len(hand) % groupSize) != 0) and ((len(hand) // groupSize) != groupSize):
            return False
        
        # Sort the given list
        hand.sort()

        # Track frequency of each number
        frequency = Counter(hand) # Counter is a subclass of dictionary

        # frequency = {}
        # for card in hand:
        #     if card in frequency:
        #         frequency[card] += 1
        #     else:
        #         frequency[card] = 1
        
        for card in hand:
            if frequency[card] == 0:
                continue
            for i in range(groupSize):
                if frequency.get(card + i, 0) > 0: # get() method returns the value for the specified key if key is in dictionary. If not, it will return the default value 0
                    frequency[card + i] -= 1
                else:
                    return False
        return True