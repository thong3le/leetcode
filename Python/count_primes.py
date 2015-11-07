class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        primes = [True] * n
        primes[:2] = [False, False]
        for p in range(2, int(n**0.5) + 1):
            if primes[p]:
                primes[p*p:n:p] = [False]*len(primes[p*p:n:p])
        return sum(primes)