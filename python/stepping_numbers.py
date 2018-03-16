from collections import deque
class Solution:
    # @param A : integer
    # @param B : integer
    # @return a list of integers
    def stepnum(self, A, B):
        queue = deque([0])
        ans = []
        while queue:
            x = queue.popleft()
            if A <= x <= B:
                ans.append(x)
            elif x > B:
                return ans
            if x == 0:
                queue.extend(range(1, 10))
            else:
                d = x%10
                if d > 0:
                    queue.append(x*10 + d-1)
                if d < 9:
                    queue.append(x*10 + d+1)
        return ans

A = 0
B = 86
print Solution().stepnum(A, B)