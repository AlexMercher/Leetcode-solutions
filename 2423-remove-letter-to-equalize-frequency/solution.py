from collections import Counter

class Solution:
    def equalFrequency(self, word: str) -> bool:
        cnt = Counter(word)
        freqs = Counter(cnt.values())  
        
        if len(freqs) == 1:
            f, c = next(iter(freqs.items()))
            return f == 1 or c == 1
        
        if len(freqs) == 2:
            items = sorted(freqs.items()) 
            (f1, c1), (f2, c2) = items
            if f1 == 1 and c1 == 1:
                return True
            if f2 - f1 == 1 and c2 == 1:
                return True
            return False
        
        return False