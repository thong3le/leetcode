class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        minprice = prices[0]
        maxpro = -2**63
        for p in prices:
            minprice = min(minprice, p)
            maxpro = max(maxpro, p - minprice)
        return maxpro