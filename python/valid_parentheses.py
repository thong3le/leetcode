class Solution(object):
	def isValid(self, s):
		if s == "":
			return True
		stack =[]
		left = ['(', '{','[']
		right = [')','}',']']
		for c in s:
			if c in right:
				if not stack or left[right.index(c)] != stack.pop():
					return False
			else:
				stack.append(c)
		return False if stack else True

print Solution().isValid("()[]{}")

