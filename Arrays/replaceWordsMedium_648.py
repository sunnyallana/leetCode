class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        
        # Initialize a set with dictionary
        roots = set(dictionary)
        
        # Search for this word's smallest prefix that exists in the roots set. If it doesn't exist, return the original word
        def findRoot(word):
            for i in range(1, len(word)):
                prefix = word[:i]
                if prefix in roots:
                    return prefix
            return word

        # Split the sentences in a list of words 
        words = sentence.split()

        # Construct the resultant string
        ans = [findRoot(word) for word in words]

        return ' '.join(ans)