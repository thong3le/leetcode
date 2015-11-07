class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	
	def getIntersectionNode(self, headA, headB):
		if not headA or not headB:
			return None
		curA = headA
        	curB = headB
        	tailA = None
        	tailB = None
        	count = 0
        	a = b = 2**63-1
        	while curA.val != curB.val:
	            	if curA.next is None:
        	        	tailA = curA
                		curA.next = headB
                		a = count
            		if curB.next is None:
                		tailB = curB
                		curB.next = headA
                		b = count
            		if count > a+b:
            			break
            		curA = curA.next
            		curB = curB.next
            		count += 1
        	else:
        		return None

       		return curA


node1 = ListNode(3)
node2 = ListNode(2)
node2.next = node1

print Solution().getIntersectionNode(node1, node2).val
