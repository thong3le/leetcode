class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = filter(lambda x: x.isalnum(), s).lower()
        return s == s[::-1]