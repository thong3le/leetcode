from collections import Counter

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        cows = [secret[i] for i in range(len(secret)) if secret[i] != guess[i]]
        cowg = [guess[i] for i in range(len(secret)) if secret[i] != guess[i]]
        
        cowscount = Counter(cows)
        cowgcount = Counter(cowg)
        bulls = 0
        for c, i in cowgcount.items():
            bulls += min(i, cowscount[c])
            
        return "%dA%dB" % (len(secret) - len(cows), bulls)