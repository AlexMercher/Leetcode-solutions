class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        count=0
        n=len(patterns)
        for i in range(0,n):
            if patterns[i] in word:
                count+=1
        return count