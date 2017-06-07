# Author: Thong Le
# Date: 05/31/2017
#
# LeetCode 4 - Median of Two Sorted Arrays
#
# Solution Approach: 
#
#
#
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        if (m == 0) and (n == 0):
            return 0
        if (m == 0):
            return nums2[n/2] if n%2 else (nums2[(n-1)/2] + nums2[n/2])/2.0
        if (n == 0):
            return nums1[m/2] if m%2 else (nums1[(m-1)/2] + nums1[m/2])/2.0
        if (m+n)%2:
            return self.ksmallest(nums1, nums2, (m+n)/2+1, 0, 0)
        else:
        	x = self.ksmallest(nums1, nums2, (m+n-1)/2+1, 0, 0)
        	y = self.ksmallest(nums1, nums2, (m+n)/2+1, 0, 0)
        	print x, y
        	return (x + y)/2.0
        
    def ksmallest(self, nums1, nums2, k, a, b):
    	print k, a, b
        if a >= len(nums1):
            return nums2[b+k-1]
        if b >= len(nums2):
            return nums1[a+k-1]
        if k == 1:
            return min(nums1[a], nums2[b])
        c, d = a + k/2 - 1, b + k/2 - 1
        if c >= len(nums1):
            return self.ksmallest(nums1, nums2, k-k/2, a, d+1)
        if d >= len(nums2):
            return self.ksmallest(nums1, nums2, k-k/2, c+1, b)
        if nums1[c] >= nums2[d]:
            return self.ksmallest(nums1, nums2, k-k/2, a, d+1)
        else:
            return self.ksmallest(nums1, nums2, k-k/2, c+1, b)

A = [1,2]
B = [1,2]

print Solution().ksmallest(A, B, 3, 0, 0)