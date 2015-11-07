# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = slow = head
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next

        tail = None
        while slow:
            slow.next, tail, slow = tail, slow, slow.next
        
        while tail:
            if tail.val != head.val:
                return False
            tail, head = tail.next, head.next
            
        return True